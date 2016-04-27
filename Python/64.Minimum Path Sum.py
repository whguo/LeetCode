#从左上角到右下角的路径中，数字和的最小值
class Solution(object):
    def minPathSum(self, grid):
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i == 0 and j > 0:
                    grid[i][j] += grid[i][j-1]
                elif j == 0 and i > 0:
                    grid[i][j] += grid[i-1][j]
                elif i > 0 and j > 0:
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1])
        return grid[len(grid) - 1][len(grid[0]) - 1]

s = Solution()
print(s.minPathSum([[1,2,3],[4,5,6],[3,4,2]]))






