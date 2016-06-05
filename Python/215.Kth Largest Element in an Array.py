#查找数组中第K大的数
class Solution(object):
    def findKthLargest(self, nums, k):
        nums = sorted(nums,reverse=1)
        return nums[k-1]

s = Solution()
print(s.findKthLargest([3,2,1,5,6,4],2))