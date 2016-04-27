#不使用乘法，除法和求模运算符，计算除法
class Solution:
    # @return an integer
    def divide(self, dividend, divisor):
        flag, ans = 0, 0
        if dividend < 0:
            flag, dividend = flag^1, -dividend  # ^运算是按位异或
        if divisor < 0:
            flag, divisor = flag^1, -divisor
        while dividend >= divisor:
            count, newDivisor = 1, divisor
            while newDivisor + newDivisor <= dividend:
                newDivisor = newDivisor + newDivisor
                count = count + count
            dividend -= newDivisor
            ans += count
        result= ans if flag == 0 else -ans
        if result>2147483647:
            return 2147483647
        elif result<-2147483648:
            return -2147483648
        return ans

s = Solution()
print(s.divide(-1,1))
