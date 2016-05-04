#求出字符串分割，使得每个子串都是回文串
import copy
class Solution(object):
    def partition(self, s):
        self.result = []
        self.dfs(s,[])
        return self.result

    def dfs(self, s, stringlist):
        if len(s) == 0: self.result.append(stringlist)
        for i in range(1, len(s)+1):
            if self.palindrome(s[:i]):
                self.dfs(s[i:], stringlist+[s[:i]])


    def palindrome(self,s):
        return s==s[::-1]

s = Solution()
print(s.partition("cbbbcc"))