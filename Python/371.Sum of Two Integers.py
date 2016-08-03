#计算两个数的和，但是不能使用+和-运算符
#Python没有无符号右移操作，并且当左移操作的结果超过最大整数范围时，会自动将int类型转换为long类型。
#int的0和正整数范围为0~0x7FFFFFFF，int负数的范围为-0x80000000~-1,因此，大于0x7FFFFFFF的其实是最高位为1（这是符号位）。
#这样算出来是把最高位不当成符号位，我们还需要对负数的情况进行修正。
#在具体实现上，我们可以先 &0x7FFFFFFF 然后取反，这样，-1变为-0x80000000(-2147483648) -2变为了-0x7FFFFFFF(-2147483647) ,因此，在^0x7FFFFFFF即可。
class Solution(object):
    def getSum(self, a, b):
        MAX_INT = 0x7FFFFFFF
        MIN_INT = 0x80000000
        MASK = 0x100000000
        while b:
            a, b = (a ^ b) % MASK, ((a & b) << 1) % MASK
        return a if a <= MAX_INT else ~((a % MIN_INT) ^ MAX_INT)

s = Solution()
print(s.getSum(35,65))

#a ^ b 直接算出a + b 每位上%2的结果， 进位的话可以直接 (a & b)<<1得到（只有两个位均为1才会进位嘛，左移表示进到下一位）

