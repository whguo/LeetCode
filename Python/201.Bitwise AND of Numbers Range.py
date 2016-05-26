#给出数的范围m--n，满足0 <= m <= n <= 2147483647，求m、n之间所有数的与运算后的结果
#如5-8,返回4
#找相同的最长前缀即可
class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        i = 0
        while m!=n and m!=0:
            m = m>>1
            n = n>>1
            i += 1
        return m<<i

s = Solution()
print(s.rangeBitwiseAnd(239,252))