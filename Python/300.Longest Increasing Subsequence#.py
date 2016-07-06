#求给出数组的最长升序序列的长度
#如给出[10, 9, 2, 5, 3, 7, 101, 18]，最长升序子序列为[2, 3, 7, 101]，返回4
#dp方法
class Solution(object):
    def lengthOfLIS(self, nums):
        l = len(nums)
        if l == 0:  return 0
        dp , maxlen = [1] * l , 0
        for i in range(l):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] =dp[i] if dp[i] > dp[j] + 1 else dp[j] + 1
            if dp[i] > maxlen:   maxlen = dp[i]
        return maxlen


s = Solution()
print(s.lengthOfLIS([10,9,2,5,3,7,101,18]))
