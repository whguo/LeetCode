#在几个垂直于x轴的线段中，找出两个，使它俩与x轴围成的面积最大
class Solution(object):
    def maxArea(self, height):
        i,j,maxregion = 0,len(height)-1,0
        while i!=j:
            maxregion = max(maxregion,(j-i)*min(height[i],height[j]))
            if height[i]<height[j]:
                i += 1
            else:
                j -= 1
        return maxregion

s = Solution()
print(s.maxArea([3,4,10,8,9]))
