#输出一个集合的所有子集
class Solution(object):
    def subsets(self, nums):
        nums = sorted(nums)
        return [[nums[x] for x in range(len(nums)) if i>>x&1] for i in range(2**len(nums))]


s = Solution()
print(s.subsets([1,2,3]))