#从数组中删掉某元素,返回删掉后的数组长度
class Solution(object):
    def removeElement(self, nums, val):
        size = 0
        for i in range(len(nums)):
            if nums[i]!=val:
                nums[size] = nums[i]
                size += 1
        return size

s = Solution()
print(s. removeElement([1,1,2,2,3],1))
