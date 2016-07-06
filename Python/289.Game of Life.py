#二维矩阵中，每个数有0(死亡)和1(存活)两个状态，它们的下一个状态由8领域中其他数的存活状态决定：
#一个存活的点，邻居中存活的个数小于2，它下一个状态死亡
#一个存活的点，邻居中存活的个数是2或3，它下一个状态存活
#一个存活的点，邻居中存活的个数大于3，它下一个状态死亡
#一个死亡的点，邻居中存活的个数等于3，它下一个状态复活
class Solution(object):
    def gameOfLife(self, board):
        m = len(board)
        if m!=0:    n = len(board[0])
        else:   return

        tmpboard = [[0 for i in range(n+2)] for j in range(m+2)]
        for i in range(m):
            for j in range(n):
                if board[i][j]==1:
                    tmpboard[i][j] += 1 ; tmpboard[i][j+1] += 1
                    tmpboard[i][j+2] += 1 ; tmpboard[i+1][j] += 1
                    tmpboard[i+1][j+2] += 1 ; tmpboard[i+2][j] += 1
                    tmpboard[i+2][j+1] += 1 ; tmpboard[i+2][j+2] += 1
        for i in range(1,m+1):
            for j in range(1,n+1):
                if board[i-1][j-1]==1:
                    board[i-1][j-1]=1 if tmpboard[i][j] in [2,3] else 0
                else:
                    board[i-1][j-1]=1 if tmpboard[i][j]==3 else 0

        return board


s = Solution()
print(s.gameOfLife([[1,0,0,1],[0,1,1,0],[1,0,1,0],[0,0,1,1]]))
