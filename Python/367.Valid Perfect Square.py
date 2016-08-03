#判断一个数是否是完全平方数，不能用开方等运算。
class Solution(object):

    #二分法，在1和Num/2之间找平方为Num的数
    def isPerfectSquare(self, num):
        L, R = 1, (num >> 1) + 1
        while L <= R:
            m = L + ((R - L) >> 1)
            mul = m ** 2
            if mul == num:
                return True
            elif mul > num:
                R = m - 1
            else:
                L = m + 1
        return False

    #蛮力法，一个一个找
    def isPerfectSquare1(self, num):
        n , i = 1 , 1
        while n<=num:
            n = i*i
            if n==num:
                return True
            elif n>num:
                return False
            i += 1

s = Solution()
print(s.isPerfectSquare(100))

