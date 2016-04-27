#返回数组的全排列(数字没有重复)
import copy
class Solution(object):
    def permute(self, nums):
        l = len(nums)
        if l==0:
            return []
        elif l==1:
            return [nums]

        i , L  = 1 , [[nums[0]]]
        while i<l:
            k = 0
            tmp = []
            while k<len(L):
                for j in range(i+1):
                    t = copy.deepcopy(L[k])
                    t.insert(j,nums[i])
                    tmp.append(t)
                k+=1
            L = tmp
            i+=1
        return L


s = Solution()
print(s.permute([4,3,2,1]))
