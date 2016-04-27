#矩阵里的元素如果为0，将该列和该行全都置为0
#如果不用额外的O(m+n)的空间，则使用矩阵的一行和一列来记录是否为0(第一个0出现的行列)
class Solution(object):
    def setZeroes(self, matrix):
        m = len(matrix)
        if m==0:
            return matrix
        n = len(matrix[0])
        vertical , horizon = [] , []
        for i in range(m):
            for j in range(n):
                if matrix[i][j]==0:
                    if not i in vertical:
                        vertical.append(i)
                    if not j in horizon:
                        horizon.append(j)
        for j in horizon:
            for k in range(m):
                matrix[k][j]=0
        for i in vertical:
            for k in range(n):
                matrix[i][k]=0
        return

s = Solution()
print(s.setZeroes([[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]]))