#在排序的循环数组中找到最小的数,二分法
class Solution(object):
    def findMin(self, nums):
        l , r = 0 , len(nums)-1
        while l<=r:
            mid = (l+r)//2
            if nums[mid]<nums[l]:
                l = l+1
                r = r-1
            elif nums[mid]<=nums[r]:
                r = mid-1
            else:
                l = mid+1
        return nums[mid]

s = Solution()
print(s.findMin([5,6,7,1,2,3,4]))
