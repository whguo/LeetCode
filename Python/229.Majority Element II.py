#返回所有的主要元素（超过1/3的）
class Solution(object):
    def majorityElement(self, nums):
        dic , l , result = {} , len(nums)//3 , []
        for n in nums:
            if dic.get(n,-1)==-1:
                dic[n] = 1
            else:
                dic[n] += 1
            if dic[n]>l:    result.append(n)
        return list(set(result))

s = Solution()
print(s.majorityElement([3,2,3,2,1,8,2,3,2,3,8,2,3]))
