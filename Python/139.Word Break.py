#判断给定的字符串能否被分成字符串字典里的小字符串
#递归，超时
class Solution(object):
    def wordBreak(self, s, wordDict):
        self.wordDict = wordDict
        return self.dfs(s)

    def dfs(self,str):
        l = len(str)
        if l==0:    return True
        for i in range(1,l+1):
            if str[:i] in self.wordDict and self.dfs(str[i:])==True:
                return True
        return False

s = Solution()
print(s.wordBreak("leetcode",{"l","eet","cod","e"}))