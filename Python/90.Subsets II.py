#求给定数组的子集(有重复数字)
import copy
class Solution(object):
    def subsetsWithDup(self, nums):
        nums = sorted(nums)
        L = []
        for i in range(2**len(nums)):
            tmp = []
            for x in range(len(nums)):
                if i>>x&1:
                    tmp.append(nums[x])
            if not tmp in L:
                t = copy.deepcopy(tmp)
                L.append(t)
        return L

s = Solution()
print(s.subsetsWithDup([1,2,2]))
