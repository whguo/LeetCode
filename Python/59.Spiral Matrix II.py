#数字按顺时针的顺序填满一个正方形
class Solution(object):
    def generateMatrix(self, n):
        matrix = [[0]*n for i in range(n)]
        i , j , x ,c = 0 , 0 , 1 , 0
        while x<=n*n:
            while x<=n*n and j<n-c:
                matrix[i][j] = x
                j , x = j+1 , x+1
            j , i =  j-1 , i+1
            while x<=n*n and i<n-c:
                matrix[i][j] = x
                i , x = i+1 , x+1
            i , j=  i-1 , j-1
            while x<=n*n and j>=c:
                matrix[i][j] = x
                j , x = j-1 , x+1
            j ,i = j+1, i-1
            while x<=n*n and i>c:
                matrix[i][j] = x
                i , x = i-1 , x+1
            i ,j = i+1 , j+1
            c += 1
        return matrix

s = Solution()
print(s.generateMatrix(4))




