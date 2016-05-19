#求出由数组中的数拼起来得到的最大数
import functools
class Solution:
    def largestNumber(self, nums):
        nums = sorted([str(x) for x in nums],key = functools.cmp_to_key(self.compare))
        ans = ''.join(nums).lstrip('0')
        return ans or '0'

    #这里比较的都是字符串
    def compare(self, a, b):
        return [1, -1][a + b > b + a]


s = Solution()
print(s.largestNumber([3,30,34,5,9]))