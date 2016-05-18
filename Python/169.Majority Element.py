#找到一个数组中的主要元素(超过一半的)，假设该元素始终存在。
class Solution(object):
    def majorityElement(self, nums):
        l = len(nums)
        if l==1:    return nums[0]
        dic , l = {} , l//2
        for n in nums:
            if dic.get(n,-1)==-1:
                dic[n] = 1
            else:
                dic[n] += 1
                if dic[n]>l:
                    return n

s = Solution()
print(s.majorityElement([1]))