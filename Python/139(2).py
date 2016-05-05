#判断给定的字符串能否被分成字符串字典里的小字符串
#优化：把不匹配的子串都存下来，可以直接跳过
class Solution(object):
    def wordBreak(self, s, wordDict):
        self.wordDict = wordDict
        self.unmatch = []
        return self.dfs(s)

    def dfs(self,str):
        l = len(str)
        if l==0:    return True
        for i in range(1,l+1):
            tmp = str[i:]
            if str[:i] in self.wordDict:
                if tmp in self.unmatch:
                    continue
                else:
                    if self.dfs(tmp)==True:
                        return True
                    else:
                        self.unmatch.append(tmp)
        return False

s = Solution()
print(s.wordBreak("leetcode",{"l","eet","cod","ee"}))