#在有序的二维数组中寻找目标数字
class Solution(object):
    def searchMatrix(self, matrix, target):
        m = len(matrix)
        if m==0:
            return False
        n = len(matrix[0])
        if n==0:
            return False
        i = 0
        while i < m:
            if matrix[i][n-1]>=target:
                break
            i+=1
        if i==m:
            return False
        else:
            j = n-1
            while j>=0 and matrix[i][j]>=target:
                if matrix[i][j]==target:
                    return True
                j-=1
            return False

s = Solution()
print(s.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,50]],53))
#本做法较慢
#想加快速度可以对最后一列和锁定行进行二分法搜索