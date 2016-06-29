#在二维矩阵中寻找是否存在一个数，矩阵每行每列有序
#从右上角开始, 比较target 和 matrix[i][j]的值. 如果小于target, 则该行不可能有此数, 所以i++;
#如果大于target, 则该列不可能有此数, 所以j--. 遇到边界则表明该矩阵不含target.
class Solution(object):
    def searchMatrix(self, matrix, target):
        m = len(matrix)
        if m!=0:    n = len(matrix[0])
        else:   return False

        i , j = 0 , n-1
        while i<m and j>=0:
            if target==matrix[i][j]:    return True
            elif target>matrix[i][j]:   i+=1
            else:   j-=1

        return False


s = Solution()
print(s.searchMatrix([[-5]],-10))

print(s.searchMatrix([  [1,   4,  7, 11, 15],
                        [2,   5,  8, 12, 19],
                        [3,   6,  9, 16, 22],
                        [10, 13, 14, 17, 24],
                        [18, 21, 23, 26, 30]] , 13))