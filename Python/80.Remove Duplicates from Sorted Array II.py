#把数组中重复两次以上的数去掉
class Solution(object):
    def removeDuplicates(self, nums):
        l , result , tag , i = len(nums) , 1 , 0 , 1
        if l<=1:
            return l
        while i<len(nums):
            if nums[i]==nums[i-1]:
                if tag!=1:
                    result += 1
                else:
                    nums.pop(i)
                    i-=1
                tag = 1
            else:
                result += 1
                tag = 0
            i += 1
        return result

s = Solution()
print(s.removeDuplicates([]))