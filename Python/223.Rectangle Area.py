#求两个矩形共同占的面积(几个字母代表矩形左下和右上的坐标)
class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):

        #可以这么来确定重复矩形的宽（高同理）：
        #用两个矩形中右边的最小值减去左边的最大值，如果这个值大于0，表示存在重复，如果这个值小于0，表示不存在重复。
        area = (C-A)*(D-B)+(G-E)*(H-F)
        width = max(min(C,G)-max(A,E),0)
        height = max(min(D,H)-max(B,F),0)
        return area-width*height

s = Solution()
print(s.computeArea(-3,0,3,4,0,-1,9,2))
