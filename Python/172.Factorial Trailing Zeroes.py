#求n！末尾有几个0
class Solution(object):
    def trailingZeroes(self, n):
        result = 0
        while n>0:
            n = n//5
            result += n
        return result

s = Solution()
print(s.trailingZeroes(124))