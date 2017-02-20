#给定一个数组，求其中的一个最大子集，要求该子集中任意的两个元素满足 x % y ==0 或者 y % x==0
#给出[1,2,4,8,10]，返回[1,2,4,8]

#若a<b且b%a==0 ,  b <c 且 c%b==0那么必然有c%a==0
class Solution(object):
    def largestDivisibleSubset(self, nums):
        if not nums: return []
        nums.sort()
        n = len(nums)
        dp, index = [1] * n, [-1] * n
        max_dp, max_index = 1, 0
        for i in range(n):
            for j in range(i-1,-1,-1):
                if nums[i] % nums[j] == 0 and dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1
                    index[i] = j

            if max_dp < dp[i]:
                max_dp, max_index = dp[i], i

        ans = []
        while max_index != -1:
            ans.append(nums[max_index])
            max_index = index[max_index]
        return ans

s = Solution()
print(s.largestDivisibleSubset([1,2,3,4,8,10]))


