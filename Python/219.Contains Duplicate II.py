#求是否存在nums[i]=nums[j]，且i与j的差不超过k
class Solution(object):
    #用字典存一下每个数最新出现的位置
    def containsNearbyDuplicate(self, nums, k):
        dic = {}
        for i in range(len(nums)):
            if dic.get(nums[i],-1)!=-1 and i-dic[nums[i]]<=k:
                return True
            dic[nums[i]] = i
        return False

    #蛮力法，超时
    def containsNearbyDuplicate1(self, nums, k):
        l = len(nums)
        if l<=1:    return False
        for i in range(l-1):
            r = l if i+k>=l else i+k
            for j in range(i+1,r):
                if nums[i]==nums[j]:
                    return True
        return False

s = Solution()
print(s.containsNearbyDuplicate([1,0,1,1],1))