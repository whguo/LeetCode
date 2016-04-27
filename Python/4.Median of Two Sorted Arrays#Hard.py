#找两个数组联合起来的中位数
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        nums = nums1+nums2
        nums = sorted(nums)
        print(nums)
        l = len(nums)
        if l%2==0:
            #return (nums[l//2-1]+nums[l//2])/2 python3使用
            return (float(nums[int(l/2-1)]+nums[int(l/2)]))/2
        else:
            return nums[l//2]

s = Solution()
print(s.findMedianSortedArrays([],[2,3]))
