#返回数组中出现频率最高的K个数
#首先扫一遍数组进行计数。
#接着用一个长度为k 堆，存储出现次数最多的元素（堆顶的元素最小，每次和堆顶的元素比较即可）
import collections
import heapq
class Solution(object):
    def topKFrequent(self, nums, k):
        counts = collections.Counter(nums)
        heap = []
        for key, cnt in counts.items():
            if len(heap) < k:
                heapq.heappush(heap, (cnt, key))
            else:
                if heap[0][0] < cnt:
                    heapq.heappop(heap)
                    heapq.heappush(heap, (cnt, key))
        return [x[1] for x in heap]


s = Solution()
print(s.topKFrequent([1,1,1,2,2,3],2))

