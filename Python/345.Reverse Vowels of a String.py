#翻转字符串中的元音字母aeiou，其他字母不动
#eg:"leetcode"=>"leotcede"
class Solution(object):
    def reverseString(self, s):
        i , j = 0 , len(s)-1
        s = list(s)
        while i<j:
            while i<j and not s[i] in ['a','e','i','o','u','A','E','I','O','U']:
                i += 1
            while i<j and not s[j] in ['a','e','i','o','u','A','E','I','O','U']:
                j -= 1
            if i<=j:
                s[i] , s[j] = s[j] , s[i]
                i , j = i+1 , j-1
        return ''.join(s)

s = Solution()
print(s.reverseString("leetcodE"))

