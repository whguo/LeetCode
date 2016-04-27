#求杨辉三角的第n行
class Solution(object):
    def generate(self, numRows):
        a = [1]
        while len(a)<=numRows:
            a = [1] + [a[x] + a[x+1] for x in range(len(a) - 1)] + [1]
        return a

s = Solution()
print(s.generate(5))