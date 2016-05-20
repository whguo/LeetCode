#把数组循环右移k次
class Solution(object):
    def rotate(self, nums, k):
        l = len(nums)
        k = k % l
        tmp = nums[0:l-k]
        nums[0:k] = nums[l-k:]
        nums[k:] = tmp
        return nums

s = Solution()
print(s.rotate([1,2,3,4,5,6,7],1))