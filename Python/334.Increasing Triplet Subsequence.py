#给出数组，判断是否存在长度为3的升序序列。
#arr[i] < arr[j] < arr[k] ， 0 ≤ i < j < k ≤ n-1
class Solution(object):
    def increasingTriplet(self, nums):
        x1 = x2 = 0x7fffffff
        for num in nums:
            if num <= x1:
                x1 = num
            elif num <= x2:  # x1 < num <= x2
                x2 = num
            else:            # x1 < x2 < num , so it return true
                return True
        return False

s = Solution()
print(s.increasingTriplet([1,3,2,5,1]))

