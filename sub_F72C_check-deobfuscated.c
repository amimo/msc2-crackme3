anonymous39 = lr0  // 0x00018f14
anonymous20 = &_3E4  // 0x00019b7c
anonymous24 = &_364  // 0x0001985c
anonymous13 = lr0  // 0x00019860
anonymous18 = a2  // 0x0001989c
anonymous19 = a1  // 0x000199a0
anonymous38 = @32[[0x2cdf4]]  // 0x00019992
anonymous25 = 0x1  // 0x000199c4
anonymous26 = 0x1  // 0x000198ac
r0_1 = 0x5e645ab4  // 0x00019880
anonymous23 = 0x1  // 0x00019872
varCC = 0x1  // 0x00019a4c
anonymous17 = 0x1  // 0x00019a4e
anonymous21 = 0x1  // 0x00019a84
anonymous22 = 0x1  // 0x00019a86
anonymous12 = 0x1  // 0x00019a88
anonymous1 = 0x1  // 0x00019ae4
anonymous11 = 0x1  // 0x00019ae6
anonymous16 = 0x1  // 0x00019a98
anonymous15 = 0x1  // 0x00019a9a
anonymous14 = 0x1  // 0x00010e20
r0_1 = 0xbc3d3bcc  // 0x0001206e
r1_24 = 0xde5516bb  // 0x0001207e
if ((((anonymous25 | anonymous26) & 0x1) == 0x0)) {
  r0_1 = r1_24 { 0xde5516bb }  // 0x000127e0
  r0_1 = 0xbc3d3bcc  // 0x000165dc
}
r2_211 = anonymous24  // 0x00013f78
@32[anonymous24] = &_1F0  // 0x00013f7a
@32[(r2_211 + 0x4)] = &_F0  // 0x00013f9c
@32[(r2_211 + 0x8)] = &_FFFFFFF0  // 0x00014a12
@32[(r2_211 + 0xc)] = anonymous13  // 0x00014bb8
@32[(r2_211 + 0x10)] = @32[r2_211]  // 0x00015f6c
anonymous3 = 0x1  // 0x00015f18
anonymous0 = 0x100  // 0x00015f08
anonymous2 = 0x0  // 0x00014b64
call sub_40190 ()
r1_211a = anonymous24  // 0x00014bc8
@32[(anonymous24 + 0x14)] = @32[(anonymous24 + 0x4)]  // 0x00014bfc
call sub_401A0 ( @32[(r1_211a + 0x14)],anonymous0,anonymous2 )
r1_211b = anonymous24  // 0x00015f58
@32[(anonymous24 + 0x18)] = @32[(anonymous24 + 0x8)]  // 0x00015f5c
@32[(r1_211b + 0x1c)] = @32[r1_211b]  // 0x00015faa
r0_211 = call sub_401E0 ( anonymous19 )
r1_211 = anonymous24  // 0x0001613c
@32[(anonymous24 + 0x20)] = r0_211  // 0x0001614c
r0_204 = anonymous3 { 0x1 }  // 0x00016df0
if ((@32[(r1_211 + 0x20)] != 0x0)) {
  r0_204 = anonymous2 { 0x0 }  // 0x00016110
}
anonymous27 = r0_204 { 0x0,0x1 }  // 0x0001637a
r0_1 = 0x1db6fa35  // 0x00016e50
r2_119 = 0xde5516bb  // 0x00016fbc
r0_1 = 0xd24c5147  // 0x00010f9e
r1_24 = 0x65b11637  // 0x00010fae
if ((anonymous27 != 0x0)) {
// block : BB_0264_0x00014db4 case: 0xd24c5147  var: r0_1
  goto LABEL_264
}
r0_1 = r1_24 { 0x65b11637 }
call sub_40220 ( @32[(anonymous24 + 0x8)],anonymous19 )
anonymous23 = 0x0  // 0x00018214
r0_1 = 0x8ceab350  // 0x00018216
while ( 0x1 ) {
// block : BB_0323_0x0001965c case: 0x8ceab350  var: r0_1
  @32[(anonymous24 + 0x5c)] = anonymous23  // 0x000194f0
  r0_1 = 0x792d758c  // 0x00019728
  anonymous28 = (@32[(anonymous24 + 0x5c)] s<= 0xff)
  r0_1 = 0xba91f21d  // 0x00017460
  r0_1 = 0xdff48d02  // 0x000163fa
  r1_24 = 0x89abd4de  // 0x00016418
  if ((anonymous28 == 0x0)) {
    break
  }
  r0_1 = 0x9351e9fd  // 0x00016940
  r0_269 = call sub_40200 ( @32[(anonymous24 + 0x5c)],@32[(anonymous24 + 0x20)] )
  r1_269 = (@32[(anonymous24 + 0x8)] + @32[(anonymous24 + 0x5c)])  // 0x00017cc4
  @32[r1_269] = (@8[(anonymous19 + r0_269)] ^ @8[r1_269])  // 0x00017ff2
  @32[(anonymous24 + 0x2c)] = (@32[(anonymous24 + 0x5c)] + 0x1)  // 0x000180a0
  r0_1 = 0x4ad9a6bd  // 0x00017b32
  r0_1 = 0x8ceab350  // 0x000123d0
  anonymous23 = @32[(anonymous24 + 0x2c)]  // 0x00012384
  continue
}
r0_1 = r1_24 { 0x89abd4de }
r0_1 = 0x45485aff  // 0x00019410
r3_17a = anonymous24  // 0x00011388
@32[(anonymous24 + 0x30)] = [0x2d120]  // 0x0001138a
r3_17 = @32[(r3_17a + 0x30)]  // 0x00011450
r2_17 = 0x1  // 0x00012712
if ((r3_17 <= 0x6540)) {
  r2_17 = 0x0  // 0x000126ec
}
anonymous29 = r2_17 { 0x0,0x1 }  // 0x00012700
r0_1 = 0x120c6ad2  // 0x00012d94
r0_1 = 0xbd4b58d2  // 0x00013a44
r1_24 = 0x606ee327  // 0x00013a52
if ((anonymous29 != 0x0)) {
// block : BB_0271_0x00015ef8 case: 0xbd4b58d2  var: r0_1
  r0_13 = 0x0  // 0x00015e74
  while ( 0x1 ) {
    varCC = r0_13 { 0x0 }  // 0x00015e76
    r0_1 = 0x8fed9ffb  // 0x00015e78
    @32[(anonymous24 + 0x60)] = varCC  // 0x00019714
    r0_1 = 0x4e7ad45c  // 0x00019394
    r2_33 = 0x1  // 0x00011a5c
    if ((@32[(anonymous24 + 0x60)] > 0xff)) {
      r2_33 = 0x0  // 0x000125c4
    }
    anonymous30 = r2_33 { 0x0,0x1 }  // 0x000127ac
    r0_1 = 0x136c59bc  // 0x000129c2
    r0_1 = 0x4581299b  // 0x00013b8a
    r1_24 = 0x233ef004  // 0x00013b9a
    if ((anonymous30 == 0x0)) {
      break
    }
    varCC = [0x2ce14]  // 0x0001248a
    anonymous3 = 0x0  // 0x000130dc
    anonymous2 = [0x2ce18]  // 0x00013174
    anonymous35 = 0x1  // 0x0001327e
    anonymous36 = 0x1  // 0x000130f0
    r0_19 = 0x6733b1cf  // 0x000131a4
    r0_19 = 0xd76eec53  // 0x00012a00
    if ((((anonymous35 | anonymous36) & 0x1) == 0x0)) {
      r0_19 = 0x42b09f30  // 0x00011bac
      call [0x40150] ()
      r0_19 = 0xd76eec53  // 0x00013148
    }
    @32[(anonymous20 + 0x18)] = call [0x40160] ()  // 0x000132aa
    r0_19 = 0x262465  // 0x0001155e
    varCC = call sub_40120 ( @32[(anonymous20 + 0x18)],0xff )
    r0_13a = call sub_40140 ( @32[(anonymous24 + 0x60)] )
    @32[(anonymous19 + r0_13a)] = (varCC ^ @8[(anonymous19 + r0_13a)])  // 0x00011c48
    r0_13 = (@32[(anonymous24 + 0x60)] + 0x1)  // 0x00011ad0
    continue
  }
  r0_1 = r1_24 { 0x233ef004 }
} else {
  r0_1 = r1_24 { 0x606ee327 }
  r0_1 = 0x63e9ab1d  // 0x00011dbc
  [0x2d120] = (@32[(anonymous24 + 0x30)] + 0x1)  // 0x00012bfc
  r0_1 = 0x6816e0aa  // 0x000122f0
  r0_1 = 0x233ef004  // 0x00017c28
}
anonymous4 = @32[(anonymous24 + 0x20)]  // 0x00011a4a
r2_31 = ((@32[[0x2ce00]] - 0x1) * @32[[0x2ce00]])  // 0x00011c88
anonymous2 = 0x1  // 0x00011c70
anonymous3 = 0x0  // 0x000119e8
anonymous0 = 0x1  // 0x000119ec
anonymous10 = @32[[0x2ce04]]  // 0x00011952
anonymous35 = 0x1  // 0x00011848
anonymous36 = 0x1  // 0x00012ac6
anonymous0 = 0x7eafc345  // 0x00010fdc
if (((((r2_31 & ~0xfffffffe) ^ 0x1) | (r2_31 & ~0xfffffffe)) == 0x0)) {
  anonymous0 = 0x8dfc2e83  // 0x00010f8c
}
anonymous2 = (0x4 * anonymous4)  // 0x00010f54
anonymous3 = zx.32(((0x4 * anonymous4) & 0x27c))  // 0x000114d6
r3_6 = (((~(anonymous4 u>> 0x6) & 0xf5d42181) | ((anonymous4 u>> 0x6) & 0x2)) ^ ((~anonymous2 & 0xf5d42181) | anonymous3))  // 0x00011674
r1_6 = 0xa1c8c252  // 0x00012958
while ( 0x1 ) {
  r0_9 = r1_6 { 0xa1c8c252,0x8dfc2e83,0x7eafc345,0x4268978d }  // 0x00011140
  r1_6 = 0x4268978d  // 0x000110f4
  if ((r0_9 > 0x7eafc344)) {
    break
  }
  if ((r0_9 != 0x8dfc2e83)) {
    if ((r0_9 != 0xa1c8c252)) {
      anonymous37 = r3_6  // 0x0001113c
      r1_6 = anonymous0 { 0x8dfc2e83,0x7eafc345 }  // 0x0001113e
    } else {
      anonymous3 = 0x1  // 0x000116e0
      r1_6 = 0x4268978d  // 0x000124d8
      anonymous2 = 0x8dfc2e83  // 0x00012476
      if ((((anonymous36 | anonymous35) & anonymous3) == 0x0)) {
        r1_6 = anonymous2 { 0x8dfc2e83 }  // 0x000116b4
      }
    }
  }
  continue
}
r0_1 = 0x511827c4  // 0x0001286c
r1_24 = 0x63eb05d8  // 0x0001287a
if ((anonymous37 != 0x3c)) {
// block : BB_0168_0x000111e4 case: 0x511827c4  var: r0_1
  while ( 0x1 ) {
    r1_11 = 0x511827c4  // 0x000111e4
    while ( 0x1 ) {
      __loop_0_exit = 0x0  // 0x00016900
      if ((r0_1 != r1_11)) {
        if ((r0_1 > 0xdd328f6a)) {
          break
        }
LABEL_264:
        r1_11 = 0xd24c5147  // 0x00015d54
        continue
      } else {
        __loop_0_exit = 0x1
        break
      }
    }
    if ((__loop_0_exit == 0x1)) {
      break
    }
    continue
  }
LABEL_109:
  anonymous14 = 0x0  // 0x00016694
LABEL_107:
  r0_1 = 0xb96a0755  // 0x00016696
  anonymous34 = (anonymous14 & 0x1)  // 0x00017172
  r0_1 = 0x6e17c5d5  // 0x000150e8
  r0_1 = 0xa8043146  // 0x00017b04
  if (((@32[[0x2cdf4]] - @32[(anonymous20 + 0x1c)]) != 0x0)) {
    call [0x40130] ()
    while ( 0x1 ) {
      continue
    }
  }
} else {
  r0_1 = r1_24 { 0x63eb05d8 }
  r0_39 = 0x0  // 0x00011120
  while ( 0x1 ) {
    // 对输入进行循环位移 
    anonymous17 = r0_39 { 0x0 }  // 0x00014a38 under-appraximation VSA, idx [0 - 255]
    r0_1 = 0x9a7a67fa  // 0x00014a3a
    r2_264 = anonymous24  // 0x00017dec
    @32[(anonymous24 + 0x64)] = anonymous17  // 0x000180c2
    r0_1 = 0xb7d7896c  // 0x00017da8
    r1_24 = 0x119e6fc1  // 0x00017db6
    if ((@32[(r2_264 + 0x64)] > 0xff)) {
      break
    }
    __loop_3_exit = 0x0  // 0x0001878e
    r0_286 = call sub_40230 ( @32[(anonymous24 + 0x64)],@32[(anonymous24 + 0x20)] )
    anonymous2 = zx.32(@8[(anonymous19 + r0_286)])  // 0x0001877e 用户输入
    anonymous4 = @32[(anonymous24 + 0x64)]  // 0x000188b8
    r1_286 = ((@32[[0x2ce80]] - 0x1) * @32[[0x2ce80]])  // 0x00018872
    anonymous17 = 0x1  // 0x00018e5a
    anonymous3 = 0x0  // 0x00018844
    anonymous0 = 0x1  // 0x00018eba
    anonymous10 = @32[[0x2ce84]]  // 0x00018b6a
    anonymous35 = 0x1  // 0x00018b7a
    anonymous36 = 0x1  // 0x00018c3c
    anonymous17 = 0x48f7ec5  // 0x00018e7a
    if (((((r1_286 & ~0xfffffffe) ^ 0x1) | (r1_286 & ~0xfffffffe)) == 0x0)) {
      anonymous17 = 0xd9a2c000  // 0x00018e28
    }
    anonymous4 = (anonymous4 %s 0x8)  // 0x00018b14
    anonymous3 = (anonymous2 u>> anonymous4)  // 0x00018e18
    anonymous0 = 0x6d0d23eb  // 0x00016f5e
    anonymous2 = (((anonymous2 << (0x8 - anonymous4)) & (anonymous2 u>> anonymous4)) | ((~(anonymous2 << (0x8 - anonymous4)) ^ 0x6d0d23eb) ^ (~(anonymous2 u>> anonymous4) ^ 0x6d0d23eb)))  // 0x000171e0
   // c = ((c << (0x8 - idx % 0x8)) | (c >> (idx % 8))) & 0xff
    r2_252 = 0x581a0c9f  // 0x0001722c
    r2_252 = 0x3654a146  // 0x0001764c
    if ((((anonymous36 | anonymous35) & 0x1) != 0x0)) {
// block : BB_0293_0x000175b4 case: 0x3654a146  var: r2_252
      while ( 0x1 ) {
        __loop_2_exit = 0x0  // 0x000175b4
        anonymous37 = anonymous2  // 0x000171f4
        r2_252 = anonymous17 { 0xd9a2c000,0x48f7ec5 }  // 0x00017510
        if ((r2_252 > 0x48f7ec4)) {
          __loop_2_exit = 0x1
          break
        } else {
// block : BB_0294_0x00017498 case: 0x1  var: r2_252
LABEL_294:
          zf250 = (r2_252 == 0xd9a2c000)
          r2_252 = 0x3654a146  // 0x00017540
          if (!zf250) {
            break
          } else {
            continue
          }
          continue
        }
      }
      if ((__loop_2_exit == 0x1)) {
        r3_260 = anonymous24  // 0x00015e06
        @32[(@32[(anonymous24 + 0x4)] + @32[(anonymous24 + 0x64)])] = anonymous37  // 0x00014a28
        r0_39 = (@32[(r3_260 + 0x64)] + 0x1)  // 0x00014b2a
        continue
      } else {
        __loop_3_exit = 0x2
        break
      }
    } else {
      __loop_3_exit = 0x1
      break
    }
  }
  if ((__loop_3_exit == 0x2)) {
    while ( 0x1 ) {
      continue
    }
  } else {
    if ((__loop_3_exit == 0x1)) {
      r2_252 = 0xd9a2c000  // 0x000175cc
      goto LABEL_294
    } else {
      r0_1 = r1_24 { 0x119e6fc1 }
      r0_108 = call [0x40170] ()
      r2_108 = anonymous24  // 0x00013b18
      @32[(anonymous24 + 0x3c)] = r0_108  // 0x00013b1a
      r0_1 = 0xbd680fb2  // 0x00013b44
      r1_24 = 0xfcb5e305  // 0x00013afc
      if ((@32[(r2_108 + 0x3c)] == 0x0)) {
        r0_1 = r1_24 { 0xfcb5e305 }
      } else {
// block : BB_0270_0x00015e68 case: 0xbd680fb2  var: r0_1
        anonymous5 = @32[(anonymous24 + 0x3c)]  // 0x00016496
        call sub_2A5D4 ( anonymous5 )
        call sub_401F0 ( ((@32[(anonymous24 + 0x3c)] ^ 0x1) & @32[(anonymous24 + 0x3c)]),0x1000 )
        r0_1 = 0xfcb5e305  // 0x00016d2c
      }
      r0_1 = 0xdecb25d3  // 0x00013e46
      r0_1 = 0x73c446df  // 0x00015630
      anonymous22 = [0x2ce88]  // 0x000173c0
      r0_273 = 0x0  // 0x000173c2
      while ( 0x1 ) { // 初始化sbox
        anonymous21 = r0_273 { 0x0 }  // 0x0001737c
        r0_1 = 0xee26f758  // 0x0001737e
        r2_241a = anonymous24  // 0x00016c78
        @32[(anonymous24 + 0x68)] = anonymous22  // 0x00014600
        @32[(r2_241a + 0x6c)] = anonymous21  // 0x00014604
        r0_1 = 0xaa152bce  // 0x00014c5c
        r1_24 = 0x859d352b  // 0x00014c78
        r2_241 = @32[(r2_241a + 0x6c)]  // 0x00014c4c
        if ((r2_241 > 0xff)) {
          break
        }
        r3_281 = anonymous24  // 0x00018454
        @32[(@32[anonymous24] + @32[(anonymous24 + 0x6c)])] = @8[@32[(anonymous24 + 0x68)]]  // 0x00018cc2
        r0_281 = call sub_40260 ( @32[(r3_281 + 0x6c)],0x5 )
        anonymous22 = (@32[(anonymous24 + 0x68)] + r0_281)  // 0x00018dd8
        r0_273 = (@32[(anonymous24 + 0x6c)] + 0x1)  // 0x00018d58
        continue
      }
      r0_1 = r1_24 { 0x859d352b }
      r0_1 = 0xebb968b6  // 0x00018fe2
      while ( 0x1 ) {
// block : BB_0253_0x00016bf0 case: 0xebb968b6  var: r0_1
        [0x2d11c] = @32[(anonymous24 + 0x1c)]  // 0x00015024
        anonymous31 = call sub_401D0 ( [0x2ce88],0x250 )[7:0]  // 0x0001596e
        r1_237a = (((@32[[0x2ce7c]] - 0x1) * @32[[0x2ce7c]]) & ~0xfffffffe)  // 0x000159f4
        r1_237 = ((r1_237a ^ 0x1) | r1_237a)  // 0x00016dc0
        r0_1 = 0xa7a909fc  // 0x00016dc2
        r2_119 = 0x9fd02765  // 0x00015930
        if ((r1_237 != 0x0)) {
          break
        }
        r0_1 = r2_119 { 0x9fd02765 }  // 0x00019b10
        [0x2d11c] = @32[(anonymous24 + 0x1c)]  // 0x00017fa8
        call sub_40210 ( [0x2ce88],0x250 )
        r0_1 = 0xebb968b6  // 0x00018854
        continue
      }
      r0_1 = 0x174c6da4  // 0x000185d4
      r1_24 = 0xd1a3be40  // 0x000185e2
      if ((anonymous31 == 0x0)) {
        r0_1 = r1_24 { 0xd1a3be40 }
        r1_119a = (((@32[[0x2ce7c]] - 0x1) * @32[[0x2ce7c]]) & ~0xfffffffe)  // 0x00014870
        r1_119 = ((r1_119a ^ 0x1) | r1_119a)  // 0x00014904
        r0_1 = 0x1509a6a8  // 0x00013fac
        r2_119 = 0xedd71fe6  // 0x00013fba
        if ((r1_119 == 0x0)) {
          r0_1 = r2_119 { 0xedd71fe6 }
          call sub_401B0 ( 0x5 )
          r0_1 = 0x1509a6a8  // 0x00014d1c
        }
        call sub_40180 ( 0x5 ) // raise (5)
        r0_1 = 0xc0c4f0c6  // 0x00013460
        r0_1 = 0x174c6da4  // 0x00014ae0
      }
      anonymous1 = 0x0  // 0x000118c6
      r0_1 = 0xf04dcf0f  // 0x0001198c
      anonymous12 = @32[(anonymous24 + 0x6c)]  // 0x000118b2 sbox长度 256
      anonymous11 = 0x0  // 0x000118b4
      while ( 0x1 ) { // rc4 加密
// block : BB_0247_0x00014528 case: 0xf04dcf0f  var: r0_1
        r0_121 = anonymous24  // 0x000144dc
        @32[(anonymous24 + 0x70)] = anonymous11  // 0x00013ea2
        @32[(r0_121 + 0x74)] = anonymous1  // 0x000143cc
        @32[(r0_121 + 0x78)] = anonymous12  // 0x000143d0
        r0_1 = 0x14a0fb97  // 0x000148b4
        while ( 0x1 ) {
// block : BB_0134_0x0001389c case: 0x14a0fb97  var: r0_1
          r2_101 = (@32[(anonymous24 + 0x74)] u>> 0x8)  // 0x000138b6
          anonymous2 = 0x0  // 0x000137c8
          zf101 = (r2_101 == 0x0)
          r2_99 = 0x1  // 0x00013800
          if (!zf101) {
            r2_99 = anonymous2 { 0x0 }  // 0x0001378c
          }
          anonymous32 = r2_99 { 0x0,0x1 }  // 0x00013916
          r2_100 = (((@32[[0x2ce7c]] - 0x1) * @32[[0x2ce7c]]) & ~0xfffffffe)  // 0x00013a34
          r2_15 = (((r2_100 | anonymous2) ^ 0x1) | (r2_100 ^ anonymous2))  // 0x00013714
          r0_1 = 0x599298df  // 0x00013716
          r1_15 = 0xc77ee655  // 0x000141b8
          if ((r2_15 != 0x0)) {
            break
          }
          r0_1 = r1_15 { 0xc77ee655 }  // 0x00018b98
          r0_1 = 0x14a0fb97  // 0x00014050
          continue
        }
        r2_15 = zx.32(anonymous32)  // 0x00012374
        r0_1 = 0xb0677e  // 0x000121a0
        r1_15 = 0x76713687  // 0x000121ae
        if ((r2_15 == 0x0)) {
          break
        }
        r0_117 = (@32[(anonymous24 + 0x78)] + 0x1)  // 0x00013dfc r0_117 : i = i + 1
        anonymous1 = 0xffffff00  // 0x00014250
        anonymous12 = (r0_117 %s 0x100)  // 0x00014264
        r0_117a = (@32[(anonymous24 + 0x1c)] + (r0_117 %s 0x100))  // 0x00014230
        anonymous3 = r0_117a  // 0x00014220
        anonymous2 = zx.32(@8[r0_117a])  // 0x00014286  sbox[i]
        anonymous11 = ((@32[(anonymous24 + 0x70)] + anonymous2) - (((((@32[(anonymous24 + 0x70)] + anonymous2) s>> 0x1f) u>> 0x18) - (-anonymous2 - @32[(anonymous24 + 0x70)])) & 0xffffff00))  // 0x00014298  (j + s[i]) % 256
        r3_117a = anonymous24  // 0x0001443c
        r1_117 = (@32[(anonymous24 + 0x1c)] + anonymous11)  // 0x0001444c  r1_117: j = (j + s[i]) % 256
        @32[r0_117a] = @8[r1_117]  // 0x00014402
        @32[r1_117] = anonymous2  // 0x000141d6                            swap(s[i], s[j])
        anonymous4 = zx.32(@8[r0_117a])  // 0x000141a4                     anonymous4 = s[j]
        anonymous0 = (@32[(r3_117a + 0x4)] + @32[(r3_117a + 0x74)])  // 0x00014196
        anonymous3 = zx.32(@8[anonymous0])  // 0x00014176
        anonymous35 = 0x1  // 0x000142ec
        anonymous36 = 0x1  // 0x000140f8
        anonymous10 = 0x7eafc345  // 0x00014356
        anonymous1 = ((anonymous4 + anonymous2) & ~anonymous1)  // 0x00014460 anonymous1 = (s[i] + s[j])  % 256
        r3_117 = (((~(anonymous3 u>> 0x5)[7:0] & 0xb9) | ((anonymous3 u>> 0x5)[7:0] & 0x6)) ^ ((~(0x8 * anonymous3) & 0xb9) | ((0x8 * anonymous3) & 0x40)))  // 0x00015b9e
        r0_2 = 0xa1c8c252  // 0x00013cc0
        while ( 0x1 ) {
          r2_86 = r0_2 { 0xa1c8c252,0x8dfc2e83,0x7eafc345,0x4268978d }  // 0x00013354
          r0_2 = 0x4268978d  // 0x00013440
          if ((r2_86 > 0x7eafc344)) {
            break
          }
          if ((r2_86 != 0x8dfc2e83)) {
            if ((r2_86 != 0xa1c8c252)) {
              anonymous37 = r3_117  // 0x00013350
              r0_2 = anonymous10 { 0x7eafc345 }  // 0x00013352
            } else {
              anonymous2 = 0x1  // 0x000134b4
              r0_2 = 0x4268978d  // 0x0001379c
              anonymous3 = 0x8dfc2e83  // 0x000134ee
              if ((((anonymous35 | anonymous36) & anonymous2) == 0x0)) {
                r0_2 = anonymous3 { 0x8dfc2e83 }  // 0x00013390
              }
            }
          }
          continue
        }
        r1_3 = zx.32(anonymous37)  // 0x000117e4
        @32[anonymous0] = anonymous37  // 0x000117e8
        anonymous2 = 0x53  // 0x00011660
        r1_3a = (r1_3 ^ 0xffffffac)  // 0x00010ec0
        r3_3 = zx.32(@8[(@32[(anonymous24 + 0x1c)] + anonymous1)])  // 0x00011602    r3_3 : k = s[s[i] + s[j]] % 256
        anonymous1 = ((~r3_3 ^ 0x53) ^ r1_3a)  // 0x00011756
        @32[anonymous0] = ((~r3_3 ^ 0x53) ^ r1_3a)  // 0x00012ab4                    data[idx] ^= k;
        anonymous3 = @32[(anonymous24 + 0x74)]  // 0x000115c4
        anonymous35 = 0x1  // 0x00012006
        anonymous4 = 0x1  // 0x00012b48
        anonymous36 = 0x1  // 0x00012b38
        anonymous1 = ((anonymous1 << (0x8 - (anonymous3 & 0x7))) | (anonymous1 u>> (anonymous3 & 0x7)))  // 0x00012aa2
        anonymous2 = 0x48f7ec5  // 0x00013026
        r0_3 = 0x581a0c9f  // 0x00011f2e
        r0_3 = 0x3654a146  // 0x000128de
        if ((((anonymous36 | anonymous35) & 0x1) != 0x0)) {
// block : BB_0233_0x00011ee0 case: 0x3654a146  var: r0_3
// block : BB_0221_0x00013e28 case: 0xb0677e  var: r0_1
          goto LABEL_233
        }
        __loop_1_exit = 0x0  // 0x00011e94
        r0_3 = 0xd9a2c000  // 0x00011020
        zf50 = (r0_3 == 0xd9a2c000)
        r0_3 = 0x3654a146  // 0x00011f72
        if (zf50) {
LABEL_233:
          anonymous37 = anonymous1  // 0x00011ff2
          r0_3 = anonymous2 { 0x48f7ec5 }  // 0x00011ff4
          @32[anonymous0] = anonymous37  // 0x00011d74
          anonymous1 = (@32[(anonymous24 + 0x74)] + 0x1)  // 0x00011d8a
          r0_1 = 0xf04dcf0f  // 0x00011d40
          continue
        } else {
          __loop_1_exit = 0x1
          break
        }
      }
      if ((__loop_1_exit == 0x1)) {
        while ( 0x1 ) {
          continue
        }
      } else {
        r0_1 = r1_15 { 0x76713687 }
        r0_1 = 0xe20b0577  // 0x00017e1e
        r1_173 = anonymous24  // 0x00015714
        @32[(anonymous24 + 0x48)] = @32[(anonymous24 + 0x4)]  // 0x00015718
        [0x2d11c] = @32[(r1_173 + 0x48)]  // 0x0001572c
        call sub_401C0 ( 0xb )
        @32[(anonymous24 + 0x4c)] = @32[(anonymous24 + 0x48)]  // 0x000166ea
        r0_1 = 0xe84312bd  // 0x00017066
        anonymous16 = 0x0  // 0x000162d6
        r0_1 = 0xe38d8dd2  // 0x000162d8
        anonymous15 = @32[(anonymous24 + 0x4c)]  // 0x00015c14
        while ( 0x1 ) { // 与代码CRC32异或
// block : BB_0259_0x00016870 case: 0xe38d8dd2  var: r0_1
          @32[(anonymous24 + 0x7c)] = anonymous15  // 0x000155d4
          @32[anonymous20] = anonymous16  // 0x000160f4
          r0_1 = 0xb45f5944  // 0x0001651a
          while ( 0x1 ) { // 
// block : BB_0300_0x00018d3c case: 0xb45f5944  var: r0_1
            r2_300 = @32[anonymous20]  // 0x00018eca
            anonymous2 = 0x0  // 0x000183a4
            cf300 = (r2_300 u>= 0x40)
            r2_287 = 0x1  // 0x00018880
            if (cf300) {
              r2_287 = anonymous2 { 0x0 }  // 0x00018890
            }
            anonymous33 = r2_287 { 0x0,0x1 }  // 0x00018dc8
            r2_290 = (((@32[[0x2ce7c]] - 0x1) * @32[[0x2ce7c]]) & ~0xfffffffe)  // 0x0001871c
            r2_15 = (((r2_290 | anonymous2) ^ 0x1) | (r2_290 ^ anonymous2))  // 0x000186aa
            r0_1 = 0xe817c58e  // 0x000186ac
            r1_15 = 0x92f823ba  // 0x00018bb0
            if ((r2_15 != 0x0)) {
              break
            }
            r0_1 = r1_15 { 0x92f823ba }
            r0_1 = 0xb45f5944  // 0x000196ee
            continue
          }
          r2_15 = zx.32(anonymous33)  // 0x00015ccc
          r0_1 = 0xee1accd5  // 0x00015c88
          r1_15 = 0xdd328f6b  // 0x00016354
          if ((r2_15 == 0x0)) {
            break
          }
          r0_1 = 0x9a51901e  // 0x00016cf4
          r2_276 = anonymous24  // 0x00018144
          @32[@32[(anonymous24 + 0x7c)]] = (@32[@32[(anonymous24 + 0x7c)]] ^ anonymous18)  // 0x000181c0   与代码CRC32异或
          @32[(r2_276 + 0x54)] = (@32[anonymous20] + 0x1)  // 0x000172c0
          @32[(r2_276 + 0x58)] = (@32[(r2_276 + 0x7c)] + 0x4)  // 0x0001730c
          r0_1 = 0xa97c1d4c  // 0x0001771c
          r0_1 = 0xe38d8dd2  // 0x000189f8
          anonymous16 = @32[(anonymous24 + 0x54)]  // 0x000189e6
          anonymous15 = @32[(anonymous24 + 0x58)]  // 0x00018958
          continue
        }
        r0_1 = r1_15 { 0xdd328f6b }
        anonymous3 = @32[(anonymous24 + 0x48)]  // 0x00013ee0
        r0_132 = 0x1  // 0x00015a30
        anonymous4 = 0xf3a14189  // 0x00015a42
        anonymous9 = 0x8522e764  // 0x000145c8
        anonymous7 = 0x64a12b0f  // 0x00014720
        anonymous8 = 0x68d28c22  // 0x000146b6
        r1_132 = 0x7b7718d1  // 0x0001466e
        anonymous14 = 0x68d28c22  // 0x0001467e
        anonymous2 = 0x68d28c22  // 0x00014f64
        anonymous0 = 0x68d28c22  // 0x00014f66
        anonymous10 = 0x68d28c22  // 0x00014f14
        anonymous14 = [0x2d01c]  // 0x00016436
        anonymous2 = 0x100  // 0x00014ef6
        r1_132 = 0xfcfe4f47  // 0x00014ef8
        r0_132 = anonymous3  // 0x00015874
        while ( 0x1 ) { // 对输入进行加密后，与加密输入比较
// block : BB_0091_0x00015f3c case: 0xfcfe4f47  var: r1_132
          r2_197 = anonymous20  // 0x00015f48
          @32[(anonymous20 + 0x14)] = anonymous14  // 0x00016d88
          @32[(r2_197 + 0x18)] = r0_132  // 0x00016d8a
          @32[(r2_197 + 0x8)] = (anonymous2 - 0x1)  // 0x000153bc
          r1_132 = 0x73dddb2b  // 0x00015428
          anonymous0 = 0x5eb5c181  // 0x000153fa
          if ((@32[(r2_197 + 0x8)] != 0x0)) {
            anonymous0 = 0x0  // 0x000160a8
            r3_184 = zx.32(@8[@32[(anonymous20 + 0x18)]])  // 0x00015ae8
            r2_184 = zx.32(@8[@32[(anonymous20 + 0x14)]])  // 0x00015ad2
            anonymous0 = 0x1  // 0x00014fd0
            if ((r3_184 != r2_184)) { // 比较数据
              anonymous0 = 0x0  // 0x00014f90 比较失败
            }
            r1_132 = 0x5eb5c181  // 0x00014f92
          } else {
            r1_132 = anonymous0 { 0x5eb5c181 }  // 0x000153cc
            anonymous0 = 0x0
          }
          r1_132 = 0xf6b54482  // 0x00016b62
          anonymous6 = 0x988d9f10  // 0x00016b46
          if (((anonymous0 & 0x1) == 0x0)) {
            break
          }
          r1_132 = anonymous9 { 0x8522e764 }  // 0x00015450
          r2_245 = anonymous20  // 0x00016e6c
          @32[(anonymous20 + 0xc)] = (@32[(anonymous20 + 0x18)] + 0x1)  // 0x000157c0
          @32[(r2_245 + 0x10)] = (@32[(r2_245 + 0x14)] + 0x1)  // 0x00014ed8
          r1_132 = anonymous4 { 0xf3a14189 }  // 0x00014eda
          r1_132 = 0xfcfe4f47  // 0x000154c4
          anonymous2 = @32[(anonymous20 + 0x8)]  // 0x00015510
          r0_132 = @32[(anonymous20 + 0xc)]  // 0x00015512
          anonymous14 = @32[(anonymous20 + 0x10)]  // 0x0001535a
          continue
        }
        r1_132 = anonymous6 { 0x988d9f10 }  // 0x00015348
        r1_123 = (@8[@32[(anonymous20 + 0x18)]] - @8[@32[(anonymous20 + 0x14)]])  // 0x00015182
        anonymous10 = r1_123  // 0x00015184
        r1_132 = 0x87898a83  // 0x00015574
        anonymous14 = 0x1  // 0x0001670a
        if ((anonymous10 != 0x0)) {
          goto LABEL_109
        }
        goto LABEL_107
      }
    }
  }
}
goto [anonymous39]

