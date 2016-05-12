#寻找数组中的一个峰值元素(比邻居大)，假设nums[-1]和nums[n]都为负无穷
class Solution(object):
    def findPeakElement(self, nums):
        i , l = 1 , len(nums)
        while i<l:
            if nums[i]<nums[i-1]:
                break
            i += 1
        return i-1

s = Solution()
print(s.findPeakElement([1,2,3,5]))