#把32位无符号数按位逆序，返回逆序后的整数
class Solution(object):
    def reverseBits(self, n):
        reversed = 0
        for i in range(32):
            reversed = (reversed << 1) | (n & 1)
            n = (n >> 1)
        return reversed

s = Solution()
print(s.reverseBits(43261596))