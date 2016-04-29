#把矩阵中被X围起来的O改为X
#思路是：先从最外边一层，用BFS把所有边界相连的'O'全换为'V',然后遍历矩阵，依然是'O'的都换成'X',是'V'的换为'O'
class Solution(object):
    def solve(self, board):
        m = len(board)
        if m <= 2 : return
        n = len(board[0])
        if n <= 2: return
        dir = ((1,0),(-1,0),(0,1),(0,-1))

        def bfs(x, y):
            if board[x][y] != 'O': return
            queue = [(x,y)]
            board[x][y] = 'V'
            while queue:
                x,y = queue.pop()
                for k in range(4):
                    nextx = x + dir[k][0]
                    nexty = y + dir[k][1]
                    if 0 <= nexty < n and 0 <= nextx < m and board[nextx][nexty] == 'O':
                        board[nextx][nexty] = 'V'
                        queue.append((nextx,nexty))

        for i in range(m):
            bfs(i,0); bfs(i,n-1) #只从边开始DFS
        for i in range(n):
            bfs(0,i); bfs(m-1,i)

        for i in range(m):
            for j in range(n):
                if board[i][j] == 'V': board[i][j] = 'O'
                elif board[i][j] == 'O': board[i][j] = 'X'
        return board

s = Solution()
print(s.solve([['X','O','X','X'],['O','X','O','X'],['X','O','X','O'],['O','X','O','X'],['X','O','X','O'],['O','X','O','X']]))