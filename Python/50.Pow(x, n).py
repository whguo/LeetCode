#实现Pow(x, n)
class Solution(object):
    def myPow(self, x, n):
        if n == 0:
            return 1
        xx = pow(x, n >> 1)
        xx *= xx
        if n & 1: xx *= x
        return xx

s = Solution()
print(s.myPow(3.1,4))

