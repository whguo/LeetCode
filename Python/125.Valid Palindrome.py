#判断一个字符串是否为回文字符串(有效字符为字母和数字，其他的不予考虑,字母不考虑大小写)
class Solution(object):
    def isPalindrome(self, s):
        newS=[i.lower() for i in s if i.isalnum()]
        return newS==newS[::-1]

s = Solution()
print(s.isPalindrome("A man, a plan, a canal: Panama"))

#isalnum 如果是字母或数字返回true，其他返回false