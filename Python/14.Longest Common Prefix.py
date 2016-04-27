#找字符串数组的最长共同前缀子串
class Solution(object):
    def longestCommonPrefix(self, strs):
        if len(strs)<=1:
            return strs[0] if len(strs)==1 else ""
        minlen = min([len(st) for st in strs])
        i = minlen
        while i>0:
            newstrs = [strs[j][0:i] for j in range(len(strs))]
            trueorfalse = [newstrs[k]==newstrs[k+1] for k in range(len(newstrs)-1)]
            if False in trueorfalse:
                i-=1
                continue
            else:
                return newstrs[0]
        return ""

s = Solution()
#print(s.longestCommonPrefix(['abcd','abc','abceee','abcfef']))
print(s.longestCommonPrefix(['a','b']))
