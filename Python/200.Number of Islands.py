#1代表陆地，0代表水，假设四周都是水，求小岛的个数
class Solution(object):
    def numIslands(self, grid):
        if grid==[]:    return 0
        self.grid = [list(l) for l in grid]
        self.num , self.n ,self.m = 0 , len(grid) , len(grid[0])
        for i in range(self.n):
            for j in range(self.m):
                if self.grid[i][j] == "1":
                    self.dfs(i,j)
                    self.num += 1
        return self.num

    def dfs(self,x,y):
        if self.grid[x][y]=="1":
            self.grid[x][y] = "0"
            if x>=1:    self.dfs(x-1,y)
            if y>=1:    self.dfs(x,y-1)
            if x+1<self.n:    self.dfs(x+1,y)
            if y+1<self.m:    self.dfs(x,y+1)

s = Solution()
print(s.numIslands(["11110","11010","11000","00000"]))
print(s.numIslands(["1"]))