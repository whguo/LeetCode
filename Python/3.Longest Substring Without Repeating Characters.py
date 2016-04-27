#找没有重复字符的最长子串
#LeetCode上运行超时
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        start,end = 0,0
        maxlen=0
        for i in range(len(s)):
            start = i
            for j in range(i+1,len(s)):
               if s[j] in s[i:j]:
                   i = j+1
                   end = j
                   break
            if len(s[start:end])>maxlen:
                maxlen=len(s[start:end])
        return maxlen

s = Solution()
l = s.lengthOfLongestSubstring('abcabcabb')
print(l)
                   
