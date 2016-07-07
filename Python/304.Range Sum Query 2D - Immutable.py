#求二维数组下标(row1,col1)和(row2,col2)之间矩形中的数之和
class NumMatrix(object):
    def __init__(self, matrix):
        self.matrix = matrix
        m = len(self.matrix)
        if m==0:    return
        else:   n = len(self.matrix[0])
        self.cursum = [[0 for j in range(n+1)] for i in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                self.cursum[i][j] = self.cursum[i-1][j]+self.cursum[i][j-1]-self.cursum[i-1][j-1]+self.matrix[i-1][j-1]

    def sumRegion(self, row1, col1, row2, col2):
        return self.cursum[row2+1][col2+1]-self.cursum[row2+1][col1]-self.cursum[row1][col2+1]+self.cursum[row1][col1]

numMatrix = NumMatrix([[3, 0, 1, 4, 2],
                       [5, 6, 3, 1, 2],
                       [1, 2, 0, 1, 5],
                       [4, 1, 0, 1, 7],
                       [1, 0, 3, 0, 5]])
print(numMatrix.sumRegion(0, 1, 2, 3))
print(numMatrix.sumRegion(1, 2, 3, 4))
