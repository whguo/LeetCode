#求出给定目标数字在有序数组中应该存放的位置
class Solution(object):
    def searchInsert(self, nums, target):
        l , r = 0 , len(nums)
        while l<r:
            mid = (l+r)//2
            if nums[mid]<target:
                l = mid+1
            else:
                r = mid
        return l



s = Solution()
print(s.searchInsert([5,7,7,8,8,10],8))
