#找3个数，使它们的和为0，返回所有结果
class Solution(object):
    def threeSum(self, nums):
        nums.sort()         #先排序
        dct, ans = {}, []
        for i in range(0, len(nums)):
            if (i > 0 and nums[i] == nums[i-1]):
                continue     #和前面一个数一样的话，跳过
            l, r = i + 1, len(nums) - 1
            while l < r:
                sum = nums[l] + nums[r] + nums[i]
                if sum == 0:
                    ans.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]: l = l + 1  #去掉重复元素
                    while l < r and nums[r] == nums[r - 1]: r = r - 1
                    l, r = l + 1, r - 1
                elif sum < 0:
                    l = l + 1
                else:
                    r = r - 1
        return ans

s = Solution()
print(s.threeSum([-2,0,1,1,2]))
