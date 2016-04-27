#最长回文子字符串
class Solution(object):
    def longestPalindrome(self, s):
        maxsub = s[0]
        for i in range(len(s)):
            for k in range(i,len(s)+1):
                sub = s[i:k]
                sublen = len(sub)
                flag = 0
                j = 0
                if sublen<=1:
                    continue
                while j <= sublen//2:
                    if sub[-(j+1)] != sub[j]:
                        break
                    j+=1
                if j==sublen//2+1:
                    flag = 1
                if flag == 1 and sublen>len(maxsub):
                     maxsub = sub
            if len(s)-i<len(maxsub):
                break
        return maxsub
s = Solution()
subb = s.longestPalindrome("abccba")
print(subb)
