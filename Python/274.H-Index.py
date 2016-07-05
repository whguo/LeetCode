#H-Index,在数组中找一个数h，使得数组中有h个数大于等于它，剩余的小于它
#注意：如果存在多个可能的h值，取最大值作为h指数。
class Solution(object):
    def hIndex(self, citations):
        for i,n in enumerate(sorted(citations,reverse = True)):
            if i>=n:    return i
        return len(citations)

s = Solution()
print(s.hIndex([3,0,6,1,5]))
