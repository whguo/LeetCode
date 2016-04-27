#返回最后一个空格前的字符串长度(最后的空格不算)
class Solution(object):
    def lengthOfLastWord(self, s):
        l = len(s)
        if l==0:
            return 0
        i = l-1
        while i>0 and s[i]==' ':
            i -= 1
        lastnotempty = i
        while i>=0 and s[i]!=' ':
            i -= 1
        return lastnotempty-i

s = Solution()
print(s.lengthOfLastWord('a abvc'))




