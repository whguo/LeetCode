#求小于非负整数N的质数个
#蛮力算法超时，不能用
#埃拉托斯特尼筛法
class Solution(object):
    def countPrimes(self, n):
        isPrime = [True] * max(n, 2)
        isPrime[0], isPrime[1] = False, False
        x = 2
        while x * x < n:
            if isPrime[x]:
                p = x * x
                while p < n:
                    isPrime[p] = False
                    p += x
            x += 1
        return sum(isPrime)

s = Solution()
print(s.countPrimes(499979))
