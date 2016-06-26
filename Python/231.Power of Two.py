#判断一个数是否是2的次方
class Solution(object):
    def isPowerOfTwo(self, n):
        if n==0:    return False
        while n & 1==0:
            n = n>>1
        return n==1

s = Solution()
print(s.isPowerOfTwo(0))
