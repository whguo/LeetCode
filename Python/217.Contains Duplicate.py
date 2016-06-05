#判断一个数组中是否有重复元素
class Solution(object):
    def containsDuplicate(self, nums):
        numset = set(nums)
        return not len(nums)==len(numset)

s = Solution()
print(s.containsDuplicate([]))