#给定数a和用数组表示的一个很大的数b，求a^b % 1337
#数学思想：c mod m = (a ⋅ b) mod m  = [(a mod m) ⋅ (b mod m)] mod m
#公式推导一下，转换成乘方的积
class Solution(object):
    def superPow(self, a, b):
        mod = 1337
        ans = 1
        for bi in b[::-1]:
            ans = ans * a ** bi % mod
            a = a ** 10 % mod
        return ans

s = Solution()
print(s.superPow(2,[1,0]))


