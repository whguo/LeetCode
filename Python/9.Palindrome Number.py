#判断一个数是否为回文数
import math
class Solution(object):
    def isPalindrome(self, x):
        if x<0:
            return False
        p,ten = 1,10
        while x>=ten:
            p+=1
            ten *= 10
        i = 0
        while i<=p//2:
            m = x//(math.pow(10,i) if i!=0 else 1)%10
            n = int(x//(math.pow(10,p-i-1))%10)
            if m==n:
                i+=1
            else:
                return False
        return True

s = Solution()
print(s.isPalindrome(-2147447412))
