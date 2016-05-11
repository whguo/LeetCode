#求出数组中乘积最大的子序列
class Solution(object):
    def maxProduct(self, nums):
        minTemp = maxTemp = MAX = nums[0]
        for i in range(1, len(nums)):
            tmp = [nums[i], nums[i] * minTemp, nums[i] * maxTemp]
            minTemp, maxTemp = min(tmp), max(tmp)
            MAX = max(maxTemp,MAX)
        return MAX

s = Solution()
print(s.maxProduct([-2,0,-1]))
