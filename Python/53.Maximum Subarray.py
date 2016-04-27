#寻找和最大的子串
class Solution(object):
    def maxSubArray(self, nums):
        ans, sum = nums[0], nums[0]
        for i in range(1, len(nums)):
            if (sum < 0):
                sum = nums[i]
            else:
                sum += nums[i]
            ans = max(ans, sum)
        return ans

s = Solution()
print(s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
print(s.maxSubArray([1]))
print(s.maxSubArray([-5,-3,-1,-2]))

