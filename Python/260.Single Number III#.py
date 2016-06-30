#给出数组，其中元素有两个只出现一次，其他的出现两次，返回出现一次的元素
#如果使用有限常量空间，那么需要使用位运算解决
class Solution(object):
    def singleNumber(self, nums):
        dic , result = {} , []
        for n in nums:
            if n in dic:
                dic[n]+=1
            else:
                dic[n] = 1
        for n in dic:
            if dic[n]!=2:
                result.append(n)
            if len(result)==2:
                return result

s = Solution()
print(s.singleNumber([1, 2, 1, 3, 2, 5]))
