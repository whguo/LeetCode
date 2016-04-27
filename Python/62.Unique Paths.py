#从左上角到右下角的不同路径数(只能向右向下)
class Solution(object):
    def uniquePaths(self, m, n):
        g = [[0] * n for i in range(m)]
        for i in range(m): g[i][0] = 1
        for j in range(n): g[0][j] = 1
        for i in range(1, m):
            for j in range(1, n):
                g[i][j] = g[i][j-1] + g[i-1][j]
        return g[m-1][n-1]

s = Solution()
print(s.uniquePaths(4,4))





