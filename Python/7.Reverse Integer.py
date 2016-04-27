#把数字翻转
import math
class Solution(object):
    def reverse(self, x):
        y = x
        l = str(abs(x))
        l = l[::-1]
        y = int(l)
        if y > math.pow(2, 31):
            return 0
        return -y if x<0 else y

s = Solution()
print(s.reverse(-123))
