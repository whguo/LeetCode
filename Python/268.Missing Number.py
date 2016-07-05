#长度为N的数组中包含0,1,2...n（缺失一个），找出缺失的那个数
class Solution(object):
    def missingNumber(self, nums):
        l = len(nums)
        nnums = [0]*(l+1)
        for i in nums:
            nnums[i] = 1
        for i in range(l+1):
            if nnums[i]==0:     return i
        return l+1

s = Solution()
print(s.missingNumber([0,1,2,3,4,5]))
