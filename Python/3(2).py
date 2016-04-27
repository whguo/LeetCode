class Solution(object):
    def lengthOfLongestSubstring(self, s):
        left = 0
        maxlen = 0
        dic = {} #用dict可以同时记下字符和位置
        for i,ch in enumerate(s):
            if ch in dic and dic[ch]>=left: #发现相同字符，左边界向后挪
                left = dic[ch] + 1
            dic[ch] = i
            maxlen = max(maxlen,i-left+1)
        return maxlen

s = Solution()
l = s.lengthOfLongestSubstring('abcabcabb')
print(l)
           
