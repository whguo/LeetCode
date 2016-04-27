#判断一个数独题目的初始状态是否正确(每行每列每个小正方形有没有重复数字)
class Solution(object):
    def isValidSudoku(self, board):
        across,vertical,square= [([] * 9) for i in range(9)],[([] * 9) for i in range(9)], [([] * 9) for i in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                if board[i][j] in across[i]:
                    return False
                else:
                    across[i].append(board[i][j])
                if board[i][j] in vertical[j]:
                    return False
                else:
                    vertical[j].append(board[i][j])
                if board[i][j] in square[(i//3)*3+j//3]:
                    return False
                else:
                    square[(i//3)*3+j//3].append(board[i][j])
        return True

s = Solution()
print(s.isValidSudoku([['5','3','.','.','7','.','.','.','.'],
                       ['6','.','.','1','9','5','.','.','.'],
                       ['.','9','8','.','.','.','.','6','.'],
                       ['8','.','.','.','6','.','.','.','3'],
                       ['4','.','.','8','.','3','.','.','1'],
                       ['7','.','.','.','2','.','.','.','6'],
                       ['.','6','.','.','.','.','2','8','.'],
                       ['.','.','.','4','1','9','.','.','5'],
                       ['.','.','.','.','8','.','.','7','9']]))
