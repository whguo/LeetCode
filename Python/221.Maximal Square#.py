#求矩阵中的最大正方形面积
#动态规划
#转移方程 dp[x][y] = min(dp[x - 1][y - 1], dp[x][y - 1], dp[x - 1][y]) + 1
class Solution(object):
    def maximalSquare(self, matrix):
        m = len(matrix)
        n = len(matrix[0]) if m else 0
        dp , result = [ [0]*n for j in range(m)] , 0
        for i in range(m):
            for j in range(n):
                dp[i][j] = 1 if matrix[i][j]=="1" else 0
                if i and j and dp[i][j]:
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1
                result = max(result,dp[i][j])
        return result*result

s = Solution()
print(s.maximalSquare([[]]))
print(s.maximalSquare(["01"]))
print(s.maximalSquare(["10100","10111","11111","10010"]))