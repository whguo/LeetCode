#1-26分别对应A-Z，求出数字串可以对应的所有字母串的个数
#动态规划做
class Solution(object):
    def numDecodings(self, s):
        if len(s) == 0:
            return 0
        dp = [1] + [0] * len(s)
        ok = lambda x: x[0] != '0' and  int(x) >= 1 and int(x) <= 26
        for i in range(1, len(s) + 1):
            dp[i] = dp[i-1] if ok(s[i-1:i]) else 0
            if i >= 2:
                dp[i]+= dp[i-2] if ok(s[i-2:i]) else 0
        return dp[len(s)]

s = Solution()
print(s.numDecodings('12'))
