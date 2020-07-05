# encoding=utf8
from binascii import unhexlify

from keystone import *

import idaapi
import idautils
from idaapi import *
from idc import *

ks = Ks(KS_ARCH_ARM, KS_MODE_THUMB)
ks_arm = Ks(KS_ARCH_ARM, KS_MODE_ARM + KS_MODE_LITTLE_ENDIAN)
MAX_BLOCK_SIZE = 256
FIX_EXTERN_CALL = True # set to False to build a runnable so


def rel(addr, base_addr):
    return hex(addr - base_addr).rstrip('L')


class CaseBlockInfo(object):
    def __init__(self, func, dispatcher, case_number, start, end=-1):
        self.func = func
        self.dispatcher = dispatcher
        self.case_number = case_number
        self.start = start
        self.end = end

    def __str__(self):
        return 'case 0x{:04x} -> [ 0x{:08x} - 0x{:08x} ]'.format(self.case_number, self.start, self.end)


class PLTBuilder(object):
    def __init__(self, seg_base, seg_size):
        add_segm_ex(seg_base, seg_base + seg_size, 0X1, 1, 2, 2, ADDSEG_NOSREG)
        set_segm_name(seg_base, "patch")
        set_segm_class(seg_base, "CODE")
        set_segm_type(seg_base, 2)
        set_default_sreg_value(seg_base, "T", 0x0)
        set_default_sreg_value(seg_base, "DS", 0x1)

        self.current_pos = seg_base

    def get_entry(self, got_entry_addr):
        entry = self.current_pos

        asm = 'bx pc\nnop'
        codes, _ = ks.asm(asm, self.current_pos)
        fill_ops(self.current_pos, codes)

        make_thumb_code(self.current_pos)
        make_thumb_code(self.current_pos + 2)

        self.current_pos += len(codes)

        asm = []
        asm.append('ldr r12, [pc, #0]')
        asm.append('ldr pc, [pc, r12]')
        asm = '\n'.join(asm)
        codes, _ = ks_arm.asm(asm)
        fill_ops(self.current_pos, codes)

        make_arm_code(self.current_pos)
        make_arm_code(self.current_pos + 4)

        self.current_pos += len(codes)

        offset = got_entry_addr - self.current_pos - 4
        offset = offset & 0xffffffff
        codes = struct.pack("<I", offset)
        fill_ops(self.current_pos, codes)
        del_items(self.current_pos)
        create_dword(self.current_pos)
        self.current_pos += len(codes)

        assert self.current_pos % 4 == 0

        return entry


OBFUCATION_HELPER_UNKOWN = 0
OBFUCATION_HELPER_DISPATCHER = 1
OBFUCATION_HELPER_LOAD_CONSTANT = 2
OBFUCATION_HELPER_BRANCH = 3
OBFUCATION_HELPER_CALL_EXTERN = 4
OBFUCATION_HELPER_INDIRECT_CALL = 5


def is_br_inst(insn):
    return insn.itype in [ARM_bl, ARM_b, ARM_bx]


def get_ldr_value(insn):
    assert insn.itype == ARM_ldr
    assert insn.Op2.type == o_mem
    value = get_dword(insn.Op2.addr)
    return value


def get_dest_reg(insn):
    assert insn.Op1.type == o_reg
    return insn.Op1.reg


def get_br_imm_target(br_inst):
    if is_br_inst(br_inst) and br_inst.Op1.type == o_near:
        return br_inst.Op1.addr
    else:
        return idaapi.BADADDR


def get_br_reg_target(br_inst):
    if is_br_inst(br_inst) and br_inst.Op1.type == o_reg:
        return get_dest_reg(br_inst)
    else:
        return -1


# 00002F4C 03 00 2D E9                 PUSH            {R0,R1}
# 00001F50 0E 10 A0 E1                 MOV             R1, LR
# 00001F54 A1 10 A0 E1                 MOV             R1, R1,LSR#1
# 00001F58 00 01 A0 E1                 MOV             R0, R0,LSL#2
# 00001F5C 04 00 80 E2                 ADD             R0, R0, #4
# 00001F60 81 10 A0 E1                 MOV             R1, R1,LSL#1
# 00001F64 00 10 91 E7                 LDR             R1, [R1,R0]
# 00001F68 01 E0 8E E0                 ADD             LR, LR, R1
# 00001F6C 03 00 BD E8                 POP             {R0,R1}
# 00001F70 08 00 9D E5                 LDR             R0, [SP,#8]
# 00001F74 08 E0 8D E5                 STR             LR, [SP,#8]
# 00001F78 00 E0 A0 E1                 MOV             LR, R0
# 00001F7C 03 80 BD E8                 POP             {R0,R1,PC}

dispatcher_code = unhexlify(
    '03002DE90E10A0E1A110A0E10001A0E1040080E28110A0E1001091E701E08EE00300BDE808009DE508E08DE500E0A0E10380BDE8')

# 00001FE4 0E 10 A0 E1                 MOV             R1, LR
# 00001FE8 A1 10 A0 E1                 MOV             R1, R1,LSR#1
# 00001FEC 81 10 A0 E1                 MOV             R1, R1,LSL#1
# 00001FF0 00 10 91 E5                 LDR             R1, [R1]
# 00001FF4 01 E0 8E E0                 ADD             LR, LR, R1
# 00001FF8 08 00 9D E5                 LDR             R0, [SP,#8]
# 00001FFC 08 E0 8D E5                 STR             LR, [SP,#8]
# 00002000 00 E0 A0 E1                 MOV             LR, R0
# 00002004 03 80 BD E8                 POP             {R0,R1,PC}

jump_helper_code = unhexlify('0E10A0E1A110A0E18110A0E1001091E501E08EE008009DE508E08DE500E0A0E10380BDE8')

# 0002A5E4                 PUSH            {R0,R1,LR}
# 0002A5E8                 MOV             R1, LR
# 0002A5EC                 MOV             R1, R1,LSR#1
# 0002A5F0                 MOV             R1, R1,LSL#1
# 0002A5F4                 LDR             R1, [R1]
# 0002A5F8                 ADD             R1, R1, LR
# 0002A5FC                 STR             R1, [SP,#0xC+var_4]
# 0002A600                 ADD             LR, LR, #4
# 0002A604                 POP             {R0,R1,PC}

jump_helper_code_2 = unhexlify('03402DE90E10A0E1A110A0E18110A0E1001091E50E1081E008108DE504E08EE20380BDE8')

# 00002034 03 40 2D E9                 STMFD           SP!, {R0,R1,LR}
# 00002038 0E 10 A0 E1                 MOV             R1, LR
# 0000203C A1 10 A0 E1                 MOV             R1, R1,LSR#1
# 00002040 81 10 A0 E1                 MOV             R1, R1,LSL#1
# 00002044 01 00 A0 E1                 MOV             R0, R1
# 00002048 00 10 91 E5                 LDR             R1, [R1]
# 0000204C 00 10 81 E0                 ADD             R1, R1, R0
# 00002050 00 10 91 E5                 LDR             R1, [R1]
# 00002054 08 10 8D E5                 STR             R1, [SP,#8]
# 00002058 04 E0 8E E2                 ADD             LR, LR, #4
# 0000205C 03 80 BD E8                 LDMFD           SP!, {R0,R1,PC}

call_extern_function_helper_code = unhexlify(
    '03402DE90E10A0E1A110A0E18110A0E10100A0E1001091E5001081E0001091E508108DE504E08EE20380BDE8')

# 00001F80 0E 10 A0 E1                 MOV             R1, LR
# 00001F84 A1 10 A0 E1                 MOV             R1, R1,LSR#1
# 00001F88 81 10 A0 E1                 MOV             R1, R1,LSL#1
# 00001F8C 01 00 A0 E1                 MOV             R0, R1
# 00001F90 00 10 91 E5                 LDR             R1, [R1]
# 00001F94 00 10 81 E0                 ADD             R1, R1, R0
# 00001F98 00 00 91 E5                 LDR             R0, [R1]
# 00001F9C 10 00 8D E5                 STR             R0, [SP,#0x10]
# 00001FA0 04 E0 8E E2                 ADD             LR, LR, #4
# 00001FA4 0C E0 8D E5                 STR             LR, [SP,#0xC]
# 00001FA8 03 40 BD E8                 LDMFD           SP!, {R0,R1,LR}
# 00001FAC 04 F0 9D E4                 LDR             PC, [SP],#4

load_constant_helper_code = unhexlify(
    '0E10A0E1A110A0E18110A0E10100A0E1001091E5001081E0000091E510008DE504E08EE20CE08DE50340BDE804F09DE4')

# 00002064 04 00 8D E5                 STR             R0, [SP,#4]
# 00002068 01 80 BD E8                 POP             {R0,PC}
indirect_call_r0 = unhexlify('04008DE50180BDE8')


def is_obfusction_helper(addr, help_code):
    code_size = len(help_code)
    codes = get_bytes(addr, code_size)
    return codes == help_code


def is_dispatcher(addr):
    return is_obfusction_helper(addr, dispatcher_code)


def is_jump_helper(addr):
    return is_obfusction_helper(addr, jump_helper_code) or is_obfusction_helper(addr, jump_helper_code_2)


def is_call_helper(addr):
    return is_obfusction_helper(addr, call_extern_function_helper_code)


def is_indirect_call_r0_helper(addr):
    return is_obfusction_helper(addr, indirect_call_r0)


def is_load_constant_helper(addr):
    return is_obfusction_helper(addr, load_constant_helper_code)


def identify_obfuscation_helper(addr):
    # bl helper
    br_insn = idautils.DecodeInstruction(addr)
    addr = get_br_imm_target(br_insn)
    if addr == idaapi.BADADDR:
        return OBFUCATION_HELPER_UNKOWN

    insn = idautils.DecodeInstruction(addr)
    if insn is None:
        return OBFUCATION_HELPER_UNKOWN
    # bx pc
    reg = get_br_reg_target(insn)
    if reg != 15:  #
        return OBFUCATION_HELPER_UNKOWN

    # ldr r12, #target
    # add pc, r12

    addr = addr + 4
    make_arm_code(addr)
    ldr_insn = idautils.DecodeInstruction(addr)
    add_insn = idautils.DecodeInstruction(addr + 4)

    if ldr_insn.itype == ARM_ldr and get_dest_reg(ldr_insn) == 12 \
            and add_insn.itype == ARM_add and get_dest_reg(add_insn) == 15:
        addr = get_ldr_value(ldr_insn)
        addr = addr + add_insn.ea + 8
        if is_dispatcher(addr):
            return OBFUCATION_HELPER_DISPATCHER
        elif is_jump_helper(addr):
            return OBFUCATION_HELPER_BRANCH
        elif is_load_constant_helper(addr):
            return OBFUCATION_HELPER_LOAD_CONSTANT
        elif is_call_helper(addr):
            return OBFUCATION_HELPER_CALL_EXTERN
        elif is_indirect_call_r0_helper(addr):
            return OBFUCATION_HELPER_INDIRECT_CALL
        else:
            return OBFUCATION_HELPER_UNKOWN


def get_reglist(regval):
    regs = []
    for n in range(16):
        reg = 1 << n
        if reg & regval:
            regs.append(n)
    return regs


def make_thumb_code(head):
    split_sreg_range(head, "T", 1, SR_user)
    del_items(head, 1)
    create_insn(head)


def make_arm_code(head):
    split_sreg_range(head, "T", 0, SR_user)
    del_items(head, 1)
    create_insn(head)


def get_case_number(ea):
    jmp_table = ea + 8
    offset = get_dword(jmp_table)
    ncase = (offset - 4) // 4
    del_items(jmp_table, 1)
    return ncase


def find_terminate_address(addr):
    head = addr
    while head < MAX_BLOCK_SIZE + 2:
        inst = idautils.DecodeInstruction(head)
        head += 2
        if inst is None:
            continue
        # pop {..., pc}
        if inst.itype == ARM_pop:
            regs = get_reglist(inst.Op1.specval)
            if 15 in regs:
                return inst.ea
        # handle more case
    return -1


def get_branch_table(func, ali_switch):
    bb = {}
    n = get_case_number(ali_switch)
    jmp_table = ali_switch + 8
    print('jmp table base:0x{:08x} case 0x{:08x}'.format(jmp_table, n))
    set_cmt(jmp_table, "jmp_table case %x" % (n), 0)
    set_cmt(jmp_table + n * 4, "case end", 0)
    prev_block_info = None
    for idx in range(0, n):
        offset = get_dword(jmp_table + idx * 4)
        # print('%x %x' % (jmp_table, offset))
        addr = jmp_table + offset - 4
        make_thumb_code(addr)
        set_cmt(addr, "case %x" % (idx), 0)
        block_info = CaseBlockInfo(func, ali_switch, idx, addr)
        if prev_block_info is not None:
            prev_block_info.end = addr - 4
        bb[idx] = block_info
        prev_block_info = block_info
    prev_block_info.end = prev_block_info.start + MAX_BLOCK_SIZE
    return bb


def bb_offset(ali_switch, idx):
    jmp_table = ali_switch + 4
    offset = get_dword(jmp_table + idx * 4)
    addr = jmp_table + offset
    return addr


def fill_nop(ea, length):
    ''' fill ea with nops '''
    codes, count = ks.asm("nop")
    c = 0
    assert (len(codes) == 2)
    while c < length:
        patch_byte(ea + c, codes[0])
        patch_byte(ea + c + 1, codes[1])
        c += 2
    make_thumb_code(ea)


def fill_ops(ea, codes):
    ''' fill ea with codes '''
    for idx, c in enumerate(codes):
        if isinstance(c, str):
            c = ord(c)
        patch_byte(ea + idx, c)
    make_thumb_code(ea)


def find_obfucation_help(addr, window_size=16):
    ''' try to find out wether the first bl target is a obfucation helper '''
    head = addr
    while head < addr + window_size:
        inst = idautils.DecodeInstruction(head)
        head += 2
        if inst is None:
            continue
        if inst.itype == ARM_bl:
            return (inst.ea, identify_obfuscation_helper(inst.ea))

    return (None, OBFUCATION_HELPER_UNKOWN)


def find_push(addr, reglist=(0, 1, 14)):
    ''' find push {r0, r1, lr} '''
    head = addr
    end = addr - 8
    while head >= end:
        make_thumb_code(head)
        inst = idautils.DecodeInstruction(head)
        head -= 2
        if inst is None:
            continue
        if inst.itype == ARM_push:
            regs = get_reglist(inst.Op1.specval)
            for reg in regs:
                if reg not in reglist:
                    return None
            else:
                return inst
    return None


def skip_nop(addr):
    inst = idautils.DecodeInstruction(addr)
    if inst and inst.itype == ARM_nop:
        return inst.ea + inst.size
    else:
        return addr


def fix_block_link(switch_info, block_info):
    block_end = block_info.end
    dispatcher = block_info.dispatcher

    head = block_info.start
    br_dispatcher_insn = None
    while head < block_end + 2:
        inst = idautils.DecodeInstruction(head)
        head += 2
        if inst is None:
            continue
        # 00019C82                 PUSH            {R0,R1,LR}
        # 00019C84                 LDR             R0, =0x16A
        # 00019C86                 LDR             R1, loc_19C88
        # 00019C88
        # 00019C88 loc_19C88                               ; CODE XREF: LOAD:0001A262↓j
        # 00019C88                                         ; LOAD:0001A97A↓j ...
        # 00019C88                 BL              sub_2A584

        print('entry block {:08x} {:08x}'.format(inst.ea, dispatcher))
        if inst.ea == dispatcher:
            br_dispatcher_insn = inst.ea - 2
            break

        if inst.itype == idaapi.ARM_bl and inst.Op1.type == o_near and inst.Op1.addr == dispatcher:
            br_dispatcher_insn = inst.ea
            break

    if br_dispatcher_insn:
        push_insn = find_push(br_dispatcher_insn)
        patch_pos = push_insn.ea
        assert push_insn
        addr = skip_nop(push_insn.ea + push_insn.size)
        print('skip_nop {:08x}'.format(push_insn.ea))
        ldr_insn = idautils.DecodeInstruction(addr)
        idx = get_ldr_value(ldr_insn)
        next_block_info = switch_info[idx]
        asm = 'b.w #%s' % (rel(next_block_info.start - 4, patch_pos))
        codes, _ = ks.asm(asm, patch_pos)
        fill_ops(patch_pos, codes)

        fill_beg = patch_pos + len(codes)
        fill_end = block_info.end
        fill_nop(fill_beg, fill_end - fill_beg)

        print('link BB: %s ==> %s' % (block_info, switch_info[idx]))
    else:
        print('successor not found BB: %s' % block_info)


def deobfuscate_block(block_info):
    block_end = block_info.end
    head = block_info.start
    while head < block_end + 2:
        inst = idautils.DecodeInstruction(head)
        head += 2
        if inst is None:
            continue

        if inst.itype == ARM_bl:
            helper_type = identify_obfuscation_helper(inst.ea)
            if helper_type == OBFUCATION_HELPER_CALL_EXTERN:
                if not FIX_EXTERN_CALL:
                    continue
                patch_pos = inst.ea
                # fill_nop(patch_pos, 8)
                print('fix call extern {:08x}'.format(inst.ea))
                offset = get_dword(inst.ea + 4)
                target = inst.ea + 4 + offset
                # print('imm {:08x}'.format(target))
                plt_entry_addr = plt_builder.get_entry(target)
                asm = 'bl #%s' % (plt_entry_addr)
                # print('br asm: ', asm)
                codes, _ = ks.asm(asm, patch_pos)
                assert len(codes) == 4
                fill_ops(patch_pos, codes)
                fill_nop(patch_pos + 4, 4)
            elif helper_type == OBFUCATION_HELPER_BRANCH:
                ea = inst.ea
                patch_pos = inst.ea
                offset = get_dword(ea + 4)
                target = (ea + 4 + offset) & 0xffffffff
                make_thumb_code(target)
                asm = 'b.w #%s' % (rel(target - 4, patch_pos))
                # print('{:08x} {:08x} {}'.format(patch_pos, ea, asm))
                codes, _ = ks.asm(asm, patch_pos)
                assert (len(codes) == 4)
                fill_ops(patch_pos, codes)
                fill_nop(patch_pos + 4, (ea + 4 + 4) - (patch_pos + 4))
            elif helper_type == OBFUCATION_HELPER_INDIRECT_CALL:
                print('patch {:x}'.format(inst.ea))
                ea = inst.ea
                patch_pos = ea
                asm = 'blx r0'
                codes, _ = ks.asm(asm, patch_pos)
                assert len(codes) == 2
                fill_ops(patch_pos, codes)
                fill_nop(patch_pos + 2, 2)
                # find push {r0, lr}
                inst = find_push(ea, [0, 14])
                assert inst
                patch_pos = inst.ea
                fill_nop(patch_pos, 2)

            continue

        if inst.itype != ARM_push:
            continue

        # push {r0, r1, lr}
        regs = get_reglist(inst.Op1.specval)
        print(regs)
        if regs[0] == 0 and regs[1] == 1 and regs[2] == 14:
            # br branch_helper
            ea, helper_type = find_obfucation_help(inst.ea + inst.size)
            if helper_type == OBFUCATION_HELPER_BRANCH:
                patch_pos = inst.ea
                print('br {:x}'.format(patch_pos))
                offset = get_dword(ea + 4)
                target = (ea + 4 + offset) & 0xffffffff
                make_thumb_code(target)
                asm = 'b.w #%s' % (rel(target - 4, patch_pos))
                # print('{:08x} {:08x} {}'.format(patch_pos, ea, asm))
                codes, _ = ks.asm(asm, patch_pos)
                assert (len(codes) == 4)
                fill_ops(patch_pos, codes)
                fill_nop(patch_pos + 4, (ea + 4 + 4) - (patch_pos + 4))
            elif helper_type == OBFUCATION_HELPER_LOAD_CONSTANT:
                patch_pos = inst.ea - 2
                # 0: sub sp, sp, #8
                # 1: push {r0,r1,lr}
                # 2: bl load_constant -> return to 4
                # 3: lr  -> dcd : offset
                # 4: pop {rt}
                # 5: next
                #
                # 0: movw rt, constant & 0xffff
                # 1: movt rt, constant >> 16

                sub_insn = idautils.DecodeInstruction(patch_pos)
                assert (sub_insn.itype == ARM_sub)

                # pop {rt}
                print('pop {:08x}'.format(ea + 8))
                pop_insn = idautils.DecodeInstruction(ea + 8)
                assert (pop_insn.itype == ARM_pop)
                regs = get_reglist(pop_insn.Op1.specval)
                assert (len(regs) == 1)
                dest_reg = regs[0]

                offset = get_dword(ea + 4)
                constant = get_dword(ea + 4 + offset)
                print('{:08x} cst {:08x}'.format(ea, constant))
                low = (constant) & 0xffff
                hi = (constant >> 16) & 0xffff
                asm = []
                asm.append('movw r{}, #0x{:x}'.format(dest_reg, low))
                if hi > 0:
                    asm.append('movt r{}, #0x{:x}'.format(dest_reg, hi))
                asm = '\n'.join(asm)
                codes, _ = ks.asm(asm, patch_pos)
                assert (len(codes) > 0)
                fill_ops(patch_pos, codes)
                fill_beg = patch_pos + len(codes)
                fill_end = pop_insn.ea + pop_insn.size
                fill_size = fill_end - fill_beg
                fill_nop(fill_beg, fill_size)
                print('load const')


def dump_brach_table(tbl):
    ncase = len(tbl)
    for case_number in range(0, ncase):
        print(tbl[case_number])


def deobfuscate_function(ali_switch):
    tbl = get_branch_table(ali_switch, ali_switch)

    ncase = len(tbl)

    make_thumb_code(ali_switch)
    entry_block_info = CaseBlockInfo(ali_switch, ali_switch, -1, ali_switch - 16, ali_switch)
    fix_block_link(tbl, entry_block_info)  # deflate llvm backend cff
    for case_number in range(0, ncase):
        fix_block_link(tbl, tbl[case_number])
        deobfuscate_block(tbl[case_number])


def find_obfuscated_functions(start, end):
    head = start
    dispatchers = []
    while head < end:
        inst = idautils.DecodeInstruction(head)
        head += 2
        if inst is None:
            continue

        if inst.itype == ARM_bl:
            helper_type = identify_obfuscation_helper(inst.ea)
            if helper_type == OBFUCATION_HELPER_DISPATCHER:
                print('found {:08x}'.format(inst.ea))
                dispatchers.append(inst.ea)

    return dispatchers


plt_builder = PLTBuilder(0x40000, 32 * 1024)
deobfuscate_function(0x00009ecc)
deobfuscate_function(0x0000c6cc)
deobfuscate_function(0x0000cdbc)
deobfuscate_function(0x0000e8c0)
deobfuscate_function(0x0000f734)
deobfuscate_function(0x00019c88)
deobfuscate_function(0x0001ded8)
deobfuscate_function(0x0001ecc0)
deobfuscate_function(0x000203e8)
deobfuscate_function(0x00020b24)
deobfuscate_function(0x00021248)
deobfuscate_function(0x00023898)
deobfuscate_function(0x0001C640)
deobfuscate_function(0x00027080)
deobfuscate_function(0x0002564C)
deobfuscate_function(0x00027934)
deobfuscate_function(0x00027FFC)
deobfuscate_function(0x000020D8)
deobfuscate_function(0x00008C84)
