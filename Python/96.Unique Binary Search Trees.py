#写出有n个数字的二叉搜索树，一共有多少种可能的形状
#0个数的共1种，空树
#1个数的共1种，1个结点
#2个数的共2种，1做根和2做根各一种，1*1+1*1
#3个数的共5种，1做根的2种，2做根的1种，3做根的2种，1*2+1*1+2*1
#..........
#n个数的情况，每个数都可以做根，设第n个数共有X[n]种，那么X[n] = X[0]*X[n-1]+X[1]*X[n-2]+...+X[n-1]*X[0]
class Solution(object):
    def numTrees(self, n):
        if n==0:
            return 1
        X = [0 for i in range(n+1)]
        X[0] , X[1] = 1 , 1
        for i in range(2,n+1):
            for j in range(i):
                X[i] += X[j] * X[i-j-1]
        return X[n]


s = Solution()
print(s.numTrees(0))

