class Solution(object):
    def isPalindrome(self, x):
        if x <= 0:
            return False if x < 0 else True
        a, b = x, 0
        while a:
            b, a = b * 10 + a % 10, a // 10
        return b == x

s = Solution()
print(s.isPalindrome(123321))