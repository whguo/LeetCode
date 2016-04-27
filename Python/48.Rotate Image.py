#将二维矩阵顺时针旋转90度

#不开辟空间的做法
class Solution(object):
    def rotate(self, matrix):
        L = len(matrix)
        R = (L + 1) // 2
        for x in range(0, R):
            for y in range(0, L - R):
                #(x,y)->(y,l-1-x)->(l-1-x,l-1-y)->(l-1-y,x)
                matrix[x][y], matrix[y][L-1-x], matrix[L-1-x][L-1-y], matrix[L-1-y][x] \
                = matrix[L-1-y][x], matrix[x][y], matrix[y][L-1-x], matrix[L-1-x][L-1-y]
        return matrix

#重新开辟空间的做法
import copy
class Solution1(object):
    def rotate(self, matrix):
        n = len(matrix)
        matrixx = copy.deepcopy(matrix)
        for i in range(n):
            for j in range(n):
                matrixx[j][n-i-1] = matrix[i][j]
        return matrixx

s = Solution()
print(s.rotate([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]))
print(s.rotate([[1,2,3],[4,5,6],[7,8,9]]))
print(s.rotate([[1,2],[3,4]]))
