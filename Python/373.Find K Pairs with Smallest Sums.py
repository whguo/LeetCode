#给出两个升序数组和一个数k，求和最小的k个数对，两个数分别来自两个数组。

#在向堆中添加新元素时，只考虑i, j + 1；（当j == 0时额外考虑i + 1, 0）
import heapq
class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        queue = []
        def push(i, j):
            if i < len(nums1) and j < len(nums2):
                heapq.heappush(queue, [nums1[i] + nums2[j], i, j])
        push(0, 0)
        pairs = []
        while queue and len(pairs) < k:
            _, i, j = heapq.heappop(queue)
            pairs.append([nums1[i], nums2[j]])
            push(i, j + 1)
            if j == 0:
                push(i + 1, 0)
        return pairs



s = Solution()
print(s.kSmallestPairs([1,7,11],[2,4,9],8))


