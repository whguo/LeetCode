#一个数字数组，只有一个数字出现一次，其他数字出现了两次，找出该数字
#思想：每个数和自身的异或是0，所以从头异或一遍，结果为单个数
#或者利用set,把所有数全都缩减为1次，做差即可
from functools import reduce
import operator

class Solution(object):
    def singleNumber(self, nums):
        return reduce(operator.xor,nums)

    def singleNumber1(self, nums):
        result = nums[0]
        for i in range(1,len(nums)):
            result = result ^ nums[i]
        return result

    def singleNumber2(self,nums):
        return 2*sum(set(nums))-sum(nums)

s = Solution()
print(s.singleNumber([1,2,1,3,2]))