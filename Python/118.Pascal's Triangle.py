#求杨辉三角
class Solution(object):
    def generate(self, numRows):
        a = [1]
        result = []
        while len(a)<=numRows:
            result.append(a)
            a = [1] + [a[x] + a[x+1] for x in range(len(a) - 1)] + [1]
        return result

s = Solution()
print(s.generate(5))