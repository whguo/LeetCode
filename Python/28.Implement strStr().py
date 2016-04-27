#匹配子串，返回第一个子串的位置，没有返回-1
class Solution(object):
    def strStr(self, haystack, needle):
        if len(needle)==0:
            return 0
        l , m = len(haystack),len(needle)
        i,j = 0,0
        while i<l and j<m:
            if haystack[i]!=needle[j]:
                i = i-j
                j = -1
            i += 1
            j += 1
        if j==m:
            return i-j
        return -1

s = Solution()
print(s.strStr('abc','d'))
