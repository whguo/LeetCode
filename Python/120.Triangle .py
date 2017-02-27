#一个三角从上到下的一条路径，求路径数值之和(每移动一行，只能跳到相邻列)
class Solution(object):
    def minimumTotal(self, triangle):
        l = len(triangle)
        if l==0:
            return 0
        elif l==1:
            return triangle[0][0]
        i = l-2
        while i>=0:
            for j in range(i+1):
                triangle[i][j] = min(triangle[i+1][j]+triangle[i][j],triangle[i+1][j+1]+triangle[i][j])
            i -= 1
        return triangle[0][0]


s = Solution()
print(s.minimumTotal([[2],[3,4],[6,5,7],[4,1,8,3]]))