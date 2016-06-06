#求k个数(0-9)和为n的所有组合
#显然用dfs做，
class Solution(object):
    def combinationSum3(self, k, n):
        self.result = []
        self.dfs([],0,k,n,1)
        return self.result

    def dfs(self,cur,cursum,k,n,level):
        if cursum==n and k==0:
            self.result.append(cur)
            return
        elif cursum>n or k<0:   return

        for i in range(level,10):
            self.dfs(cur+[i],cursum+i,k-1,n,i+1)

s = Solution()
print(s.combinationSum3(3,22))