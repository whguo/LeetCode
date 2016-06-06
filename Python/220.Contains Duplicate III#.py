#求是否存在nums[i]与nums[j]的差不超过t，且i与j的差不超过k
import collections
class Solution(object):
    #用排序字典 |nums[i] - nums[j]| <= t <=> |nums[i]/t - nums[j]/t| <= 1
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        if k<1 or t<0:  return False
        dic = collections.OrderedDict()
        for i in range(len(nums)):
            key = nums[i] / max(1, t)
            for m in (key, key - 1, key + 1):
                if m in dic and abs(nums[i] - dic[m]) <= t:
                    return True
            dic[key] = nums[i]
            if i >= k:
                dic.popitem(last=False)
        return False

    #蛮力法超时
    def containsNearbyAlmostDuplicate1(self, nums, k, t):
        l = len(nums)
        for i in range(l):
            r = l if l<=i+k else i+k
            for j in range(i+1,r):
                if abs(nums[i]-nums[j])<=t:
                    return True
        return False

s = Solution()
print(s.containsNearbyAlmostDuplicate([1,0,1,1],1,3))