#有序数组，返回它的摘要集，连续数字作为一个摘要
#For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
class Solution(object):
    def summaryRanges(self, nums):
        if nums==[]:    return []
        result , start , l = [] , nums[0] , len(nums)
        for i in range(1,l):
            if nums[i]!=nums[i-1]+1:
                string = str(start) if nums[i-1]==start else str(start)+"->"+str(nums[i-1])
                result.append(string)
                start = nums[i]
        string = str(start) if nums[-1]==start else str(start)+"->"+str(nums[-1])
        result.append(string)
        return result

s = Solution()
print(s.summaryRanges([0,1,2,3]))
