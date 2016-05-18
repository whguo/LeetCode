#把字符串转化成对应的数字，A->1，B->2....AA->27，AB->28
class Solution(object):
    def titleToNumber(self, s):
        s = s[::-1]
        result = ord(s[0])-64
        for i in range(1,len(s)):
            result +=  26**i*(ord(s[i])-64)
        return result


s = Solution()
print(s.titleToNumber("ABC"))