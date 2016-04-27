#从左上角到右下角的不同路径数(只能向右向下),有'1'的位置是障碍
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        m = len(obstacleGrid)
        if m==0:
            return 0
        n = len(obstacleGrid[0])
        g = [[0] * n for i in range(m)]
        for i in range(m):
            if obstacleGrid[i][0] == 1: break
            else: g[i][0] = 1
        for j in range(n):
            if obstacleGrid[0][j] == 1: break
            else: g[0][j] = 1
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j]==0:
                    g[i][j] = g[i][j-1] + g[i-1][j]
                else:
                    g[i][j] = 0
        return g[m-1][n-1]

s = Solution()
print(s.uniquePathsWithObstacles([[0,0,0],[0,1,0],[0,0,0]]))
print(s.uniquePathsWithObstacles([[1,0]]))





