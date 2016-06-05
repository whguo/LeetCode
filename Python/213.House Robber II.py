#抢劫，依然是相邻两个家庭会触发警报，但是这个街区是圆形的，第一家和最后一家相邻。求最大收益
#由于第一家和最后一家不能同时出现，分别去掉第一家和最后一家各求一次，比较即可
class Solution(object):
    def rob(self, nums):
        l = len(nums)
        if l == 0:    return 0
        if l == 1:    return nums[0]
        dp = [0] * l
        #去掉第一个
        dp[0], dp[1] = 0, nums[1]
        for i in range(2, l):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        answer = dp[l - 1]
        #去掉最后一个
        dp[0], dp[1] = nums[0], max(nums[0], nums[1])
        for i in range(2, l-1):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        return max(dp[l - 2], answer)

s = Solution()
print(s.rob([3,1,2,7,9,13,11]))