#爬楼梯，一次可以爬一阶或两阶，问到达N阶台阶有多少种不同走法
class Solution(object):
    def climbStairs(self, n):
        f , i = [1 , 1] , 0
        while i<n:
            f.append(f[-1]+f[-2])
            i += 1
        return f[n]

s = Solution()
print(s.climbStairs(5))