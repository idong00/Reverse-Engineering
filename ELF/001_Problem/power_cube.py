from hashlib import sha256

max_loop_count = 0x456BEEFCAFEBABE
var_4010 = 0xDEADBEEFDEADBEEF

calc_value = pow(var_4010, pow(3, max_loop_count, 2**64), 2**64)

var_30 = sha256(int.to_bytes(calc_value, 8, "little")).digest()

a0123456789abcd = "0123456789abcdef"		
result = [None] * 0x40

for index in range(0x1F + 1):
    result[index << 1] = a0123456789abcd[var_30[index] >> 4]
    result[(index << 1) + 1] = a0123456789abcd[var_30[index] & 0x0F]

print("DH{{{0}}}".format("".join(result)))