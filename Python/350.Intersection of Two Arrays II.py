#返回两个数组的交集
import collections
class Solution(object):
    def intersection(self, nums1, nums2):
        count1 = collections.Counter(nums1)
        count2 = collections.Counter(nums2)
        result = []
        for key,count in count1.items():
            if count2.get(key,-1)!=-1:
                result += [key]*min(count,count2[key])
        return result

s = Solution()
print(s.intersection([1,2,2,1],[2,2]))

