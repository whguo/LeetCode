#判断两个字符串是否是“相同字符异序词”
class Solution(object):
    def isAnagram(self, s, t):
        if len(s)!=len(t):  return False
        dic1 , dic2 = {}, {}
        for ch in s:
            if dic1.get(ch,-1)==-1:
                dic1[ch] = 1
            else:
                dic1[ch] += 1
        for ch in t:
            if dic2.get(ch,-1)==-1:
                dic2[ch] = 1
            else:
                dic2[ch] += 1
        return dic1==dic2

s = Solution()
print(s.isAnagram("anagram","nagaram"))