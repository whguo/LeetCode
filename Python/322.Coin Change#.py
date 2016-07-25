#给出数字集合coin和总数amount，问用coin中数如何加起来能得到amount，使得数字个数最少，返回最少个数。
#不能得到返回-1。
#动态规划，状态转移方程
#dp[x + c] = min(dp[x] + 1, dp[x + c])
#其中dp[x]代表凑齐金额x所需的最少硬币数，c为可用的硬币面值
class Solution(object):
    def coinChange(self, coins, amount):
        dp = [0] + [-1] * amount
        for x in range(amount):
            if dp[x] < 0:
                continue
            for c in coins:
                if x + c > amount:
                    continue
                if dp[x + c] < 0 or dp[x + c] > dp[x] + 1:
                    dp[x + c] = dp[x] + 1
        return dp[amount]

s = Solution()
print(s.coinChange([1,2,5],11))
