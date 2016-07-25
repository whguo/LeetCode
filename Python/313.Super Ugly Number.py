#Super Ugly Number：正整数，它的所有质因数都在给定的质数列表里。
#求第n个Super Ugly Number。
#eg：primes = [2, 7, 13, 19]
#[1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]是前12个super ugly number。
class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        uglynumber = [1]*n
        flag = [1]*len(primes)
        flagres = [x for x in primes]
        i = 1
        while i<n:
            tmpmin = min(flagres)
            for j in range(len(primes)):
                if tmpmin==flagres[j]:
                    flag[j] += 1
                    uglynumber[i] = tmpmin
                    flagres[j] = uglynumber[flag[j]-1]*primes[j]
                    break
            i+=1
            if tmpmin==uglynumber[i-2]:
                i-=1
        return uglynumber[n-1]

s = Solution()
print(s.nthSuperUglyNumber(12,[2,7,13,19]))
