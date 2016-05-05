#一个数字数组，其他数字出现了三次，只有一个数字出现不是三次，找出该数字
class Solution(object):
    def singleNumber(self, nums):
        dic = {}
        for n in nums:
            if n in dic:
                dic[n]+=1
            else:
                dic[n] = 1
        for n in dic:
            if dic[n]!=3:
                return n

s = Solution()
print(s.singleNumber([1,2,1,3,2,1,2]))