#写出n个数的中k个数的所有组合(C(n,k))
import copy
class Solution(object):
    def combine(self, n, k):
        self.nums , self.n , self.k = range(1,n+1) , n , k
        self.L = []
        self.dfs(0,0,[])
        return self.L

    def dfs(self,deep,start,tmp):
        if deep==self.k:
            t = copy.deepcopy(tmp)
            self.L.append(t)
            tmp.pop()
            return
        else:
            for i in range(start,self.n):
                tmp.append(self.nums[i])
                self.dfs(deep+1,i+1,tmp)
            if not tmp==[]:
                tmp.pop()


s = Solution()
print(s.combine(5,2))