#给出一个非负整数n，求0到10的n次方之间有多少数是数字没有重复的
#例如：n=2，返回91，有重复的是11,22...99共9个。

#排列组合题
#设i为长度为i的各个位置上数字互不相同的数。
#i==1 : 10（0~9共10个数，均不重复）
#i==2: 9 * 9 （第一个位置上除0外有9种选择，第2个位置上除第一个已经选择的数，还包括数字0，也有9种选择）
#i ==3: 9* 9 * 8 （前面两个位置同i==2，第三个位置除前两个位置已经选择的数还有8个数可以用）
#……
#i== n: 9 * 9 * 8 *…… (9-i+2)
#需要注意的是，9- i + 2 >0 即 i < 11，也就是i最大为10，正好把每个数都用了一遍。以后i再增大，不重复的数也不会变多。
class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        n = min(n, 10)
        dp = [1] + [9] * n  # 9 - n + 2 > 0 => 11 > n
        for i in range(2, n + 1):
            for x in range(9, 9 - i + 1, -1):
                dp[i] *= x
        return sum(dp)


s = Solution()
print(s.countNumbersWithUniqueDigits(3))

