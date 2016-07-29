#返回两个数组的交集
class Solution(object):
    def intersection(self, nums1, nums2):
        return list(set(nums1)&set(nums2))

s = Solution()
print(s.intersection([1,2,2,1],[2,2]))

