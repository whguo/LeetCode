#给一个数，返回它最少是几个数的平方和
#例如：12=4+4+4，返回3,13=4+9返回2
import math
class Solution(object):
    #四平方和定理：任意一个正整数均可表示为4个以内整数的平方和
    def numSquares(self, n):
        while (n % 4 == 0): n /= 4
        if (n % 8 == 7):    return 4
        a = 0
        while a*a<=n:
            b = int(math.sqrt(n - a * a))
            if (a * a + b * b == n):
                return 2 if a>0 and b>0 else 1
            a += 1
        return 3

    #dfs超时
    def numSquares1(self, n):
        self.L = [i*i for i in range(1,int(math.sqrt(n))+1)]
        l , self.result = len(self.L) , n
        self.dfs(n,l-1,0) if l!=1 else n
        return self.result

    def dfs(self,cursum,flag,level):
        if level>self.result:   return
        if cursum==0: return level
        for i in range(flag,-1,-1):
            if self.result*self.L[i]<cursum:    return
            if cursum>self.L[i]:
                tmp = self.dfs(cursum-self.L[i],i,level+1)
                if tmp!=None:    self.result = min(self.result,tmp)
                if self.result==2:  return
            if cursum==self.L[i]:
                self.result = min(self.result,level+1)

s = Solution()
print(s.numSquares(137))
