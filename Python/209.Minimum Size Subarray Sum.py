#求出最短子数组，要求他们得和大于等于给定数s
class Solution(object):
    def minSubArrayLen(self, s, nums):
        start , end , cursum = 0, 0 , 0
        l = len(nums)
        minlen = l+1
        while end < l:
            cursum += nums[end]
            while cursum>=s:
                minlen = min(minlen,end-start+1)
                cursum -= nums[start]
                start+=1
            end += 1
        if minlen==l+1:
            return 0
        return minlen


s = Solution()
print(s.minSubArrayLen(100,[]))