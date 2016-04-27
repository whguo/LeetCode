#求n位数的格雷码(二进制中每次更改一位)
class Solution(object):
    def grayCode(self, n):
        tmp , result = 0 , [0]
        for x in range(2**n-1):
            for i in range(n):
                t = tmp^(2**i)
                if not t in result:
                    result.append(t)
                    tmp = t
                    break
        return result

s = Solution()
print(s.grayCode(3))
