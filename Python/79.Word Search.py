#在二维字母矩阵中寻找给定的字母串，两个字母相邻即可(上下左右)
#深度优先搜索即可
class Solution:
    def exist(self, board, word):
        self.h = len(board)
        self.w = len(board[0])
        self.covered = [[0 for i in range(self.w)] for j in range(self.h)]
        if len(word)==0:
            return False
        for i in range(self.h):
            for j in range(self.w):
                if board[i][j]==word[0]:
                    if self.dfs(i,j,0,board,word)==True:
                        return True
        return False

    def dfs(self,i,j,k,board,word):
        if k==len(word)-1:
            return True
        self.covered[i][j] = 1
        if i>0 and self.covered[i-1][j]==0 and board[i-1][j]==word[k+1]:
            if self.dfs(i-1,j,k+1,board,word)==True:
                return True
        if j>0 and self.covered[i][j-1]==0 and board[i][j-1]==word[k+1]:
            if self.dfs(i,j-1,k+1,board,word)==True:
                return True
        if i<self.h-1 and self.covered[i+1][j]==0 and board[i+1][j]==word[k+1]:
            if self.dfs(i+1,j,k+1,board,word)==True:
                return True
        if j<self.w-1 and self.covered[i][j+1]==0 and board[i][j+1]==word[k+1]:
            if self.dfs(i,j+1,k+1,board,word)==True:
                return True
        self.covered[i][j] = 0
        return False


s = Solution()
print(s.exist([['A','B','C','E'],['B','F','C','S'],['A','D','E','E']],"ABADEC"))