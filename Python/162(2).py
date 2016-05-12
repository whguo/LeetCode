#寻找数组中的一个峰值元素(比邻居大)，假设nums[-1]和nums[n]都为负无穷
#二分法：
#思路：如果中间元素大于其相邻后续元素，则中间元素左侧(包含该中间元素）
#必包含一个局部最大值。如果中间元素小于其相邻后续元素，则中间元素右侧必包含一个局部最大值。
class Solution(object):
    def findPeakElement(self, nums):
        l , r = 0 , len(nums)-1
        while l<=r:
            if l==r:    return l
            mid = (l+r)//2
            if nums[mid]<nums[mid+1]:
                l = mid+1
            else:
                r = mid

s = Solution()
print(s.findPeakElement([1,2,3,1]))