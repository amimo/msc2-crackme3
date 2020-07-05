# msc2-crackme3

阿里2015第二届安全挑战赛第三题题解

* ali-crackme-deobfuscation.py 清理后端混淆ida脚本
* solve.py 解答，包含加解密算法
* sub_*.c 关键函数，反混淆前后伪码
* libcrackme-clean.so 清理后端混淆后的二进制
* libcrackme-clean-memory-trace.zip 反混淆后抓的一个内存trace，测试输入"zzzzzzzszzzzzzz"
* libcrackme-memory-trace.zip 使用原始so抓取的有内存trace，解密使用的sbox和xor key需要从这个trace提取。
* libcrackme-clean-database.idc 在IDA导入该idc后，所有函数都可以正常反编译。