#不是O(n)的算法，效率仍然不高
class Solution(object):
    def longestPalindrome(self, s):
        maxsub = s[0]
        l = len(s)
        for i in range(l):
            for j in range(i,l-i):
                if s[i]!=s[-(j+1)]:
                    continue
                if l-i-j<=len(maxsub):
                    break
                k = i
                m = j+1
                while k+m<l:
                    if s[k]!=s[-m]:
                        break
                    k+=1
                    m+=1
                if k+m>=l and l-i-j>len(maxsub):
                    maxsub = s[i:l-j]
                    break
            if len(maxsub)==l-i:
                break
        return maxsub
s = Solution()
subb = s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaa")
print(subb)
