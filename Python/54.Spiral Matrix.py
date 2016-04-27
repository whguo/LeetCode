#把矩阵(m*n)中的数按照顺时针顺序输出
class Solution(object):
    def spiralOrder(self, matrix):
        m = len(matrix)
        if m==0:
            return []
        n = len(matrix[0])
        i , j , x ,c ,l = 0 , 0 , 0 , 0 , []
        while x<m*n:
            while x<m*n and j<n-c:
                l.append(matrix[i][j])
                j , x = j+1 , x+1
            j , i =  j-1 , i+1
            while x<m*n and i<m-c:
                l.append(matrix[i][j])
                i , x = i+1 , x+1
            i , j=  i-1 , j-1
            while x<m*n and j>=c:
                l.append(matrix[i][j])
                j , x = j-1 , x+1
            j ,i = j+1, i-1
            while x<m*n and i>c:
                l.append(matrix[i][j])
                i , x = i-1 , x+1
            i ,j = i+1 , j+1
            c += 1
        return l

s = Solution()
print(s.spiralOrder([]))
print(s.spiralOrder([[1],[2]]))
print(s.spiralOrder([[]]))
print(s.spiralOrder([[1,2],[3,4]]))
print(s.spiralOrder([[1,2],[3,4],[5,6],[7,8],[9,10],[11,12],[13,14],[15,16]]))


