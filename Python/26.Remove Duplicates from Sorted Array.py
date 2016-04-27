#删掉有序数组中的重复元素
class Solution(object):
    def removeDuplicates(self, nums):
        l = len(nums)
        if l==0:
            return 0
        elif l==1:
            return 1
        total = 1
        for i in range(1,l):
            if nums[i]!=nums[i-1]:
                total+=1
        return total

s = Solution()
print(s.removeDuplicates([1,1,2,2,3]))
