#找两个数的和为目标数
class Solution(object):
    def twoSum(self, nums, target):
        for i,x in enumerate(nums):
            for j,y in enumerate(nums):
                if x+y == target and i!=j:
                    return ([i,j])
        return None
    
s = Solution()
L = s.twoSum([2,7,11,13],9)
print(L)
