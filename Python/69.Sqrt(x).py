#求整数的平方根，向下 取整
#牛顿迭代法：初值可以任意选择
class Solution:
    def sqrt(self, x):
        y0, y1 = 0, 1
        while int(y0) != int(y1):
            y0 = y1
            y1 = 1.0/2.0 * (y0 + x / y0)
        return int(y0)

s = Solution()
print(s.sqrt(25))