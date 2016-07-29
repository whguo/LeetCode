#把一个2到58的正整数拆成几个数的和，使得他们的乘积最大，返回最大乘积。

#在n >3的情况下，我们处理一个数拆分成2，要么拆分成3，（4的话相当于2个2 ， 拆成1的话乘积太小了）
#可以说，拆成3的比拆成2的乘积大。 比如6的时候 2*2*2 < 3*3
#我们希望能尽可能的拆成3，然后才是2.
#所以，如果
#n % 3 == 0:  那么全部拆成3
#n % 3 == 1:  2个2剩下的为3    4*3^(x-1) > 1*3^x
#n % 3 == 2:  1个2剩下的为3
class Solution(object):
    def integerBreak(self, n):
        if n <= 3 :return n-1
        mod = n % 3
        if mod == 0: return int(pow(3, n / 3))
        if mod == 1: return int(4 * pow(3, (n - 4) / 3))
        return int(2 * pow(3, n / 3))

s = Solution()
print(s.integerBreak(15))

