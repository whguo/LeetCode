#判断给定数是否是3的次方
class Solution(object):
    def isPowerOfThree(self, n):
        while n>8:
            if n%3==0:
                n = n//3
            else:   return False
        return n==1 or n==3

s = Solution()
print(s.isPowerOfThree(19684))
