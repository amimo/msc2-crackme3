from binascii import unhexlify

sbox = list(unhexlify(
    'F96BE81F2BBB3C604ACC8B32221E3973'
    '367E4C4041388F84374FFA0B8D969AA9'
    'EF3000CB9995AC34275B5405D4C62863'
    '18C24B55897A497FAF4D8726E3479879'
    'D371147DC18C6DDAEDA10A3EF276B256'
    '7CEABF90015DBCDF0EA76E8A676AAEE6'
    'CFB01AFD5066FFC511EE9785DCA4CEEC'
    'C7159E880C94BEAAC0AD532C813F6880'
    '12480283211DB116DD1025D2A0777404'
    'D6D1ABE1D78623515C61E5BDE75FF5D0'
    '582A4262B6249246C84ECA64D965BAB7'
    '9DA5E9DBB8F07B3BB3F4DE7044A66C78'
    '1B9FEB17E09BFE133D520975CD030DF7'
    '3AE4C9D820F3314582F65AD58EC32E6F'
    'C4A25708E22F59F87291B5431C5E35FC'
    '0669A3B9FBA8B4932D339C19070FF129'
))

encrypt_data = list(unhexlify(
    '6DC4AD347C649C39171726A7BA1828D2'
    'D5DD27BA862A0E27C4EEC431F7356214'
    '6C4118B877FA5CF0A4202590166C9143'
    '4908A4258E84A147027465B6AFAE45D6'
    '6D2F5393EAF2D488F3DB8738E0FC7E1C'
    '8E73826D6A27E2E864271B970D3205C9'
    'C67EBF9FB8DBCC8536B9ABE5A7F976FB'
    '0B917116404941814CC99247933B528C'
    'A5E1663AB0339086A5209DBFF471962D'
    'AD521D09CC92C1E37306FB92A7F538A7'
    '1AFE09375BABD98996A28A1AF6C92BC6'
    '8E35073387D1A7E34C824B89031A8E7F'
    '7D85E4B5FBF91EF6F7AC79624BB401C4'
    '9967F67D2DF2A8A66B1F67E45915C9EF'
    '2618C42CD654FE33BEF38CCFF85B5F06'
    '2BC218B6801DBA93FF11E92A5DA39597'
))


def encrypt(data):
    i = 0
    j = 0
    for idx in range(0, 256):
        data[idx] = (data[idx] >> 5 | data[idx] << 3) & 0xff  # 第二次
        i = (i + 1) % 256
        j = (j + sbox[i]) % 256
        sbox[i], sbox[j] = sbox[j], sbox[i]
        k = sbox[(sbox[i] + sbox[j]) % 256]
        data[idx] ^= k  # 第三次
        c = data[idx]
        data[idx] = ((c << (8 - (idx % 8))) | (c >> (idx % 8))) & 0xff  # 第四次

        data[idx] ^= 0x29  # 第五次
        c = data[idx]
        c = ((c >> (0x8 - idx % 8)) | (c << idx % 8)) & 0xff
        data[idx] = c  # 第六次
    return data


def decrypt(data):
    i = 0
    j = 0
    for idx in range(0, 256):
        c = data[idx]
        c = ((c << (0x8 - idx % 0x8)) | (c >> (idx % 8))) & 0xff
        c ^= 0x29
        data[idx] = c

        data[idx] = ((c >> (8 - (idx % 8))) | (c << (idx % 8))) & 0xff

        i = (i + 1) % 256

        j = (j + sbox[i]) % 256
        sbox[i], sbox[j] = sbox[j], sbox[i]
        k = sbox[(sbox[i] + sbox[j]) % 256]
        data[idx] ^= k

        data[idx] = (data[idx] << 5 | data[idx] >> 3) & 0xff

    return data


xor_key = unhexlify('208e1339')
for i in range(256):
    encrypt_data[i] ^= xor_key[i % 4]  # 第七次

encrypt_data = decrypt(encrypt_data)

flag = ''
for idx, c in enumerate(encrypt_data[:15]):
    c = ((c >> (0x8 - idx % 8)) | (c << idx % 8)) & 0xff
    flag += chr(c)

print('flag:', flag)
