#入室抢劫，数组代表每个室内的钱，相邻两个房子被抢会触发警报，求最大收益
class Solution(object):
    #动态规划
    #比如说nums为{3, 2, 1, 5}，那么我们来看我们的dp数组应该是什么样的，
    # 首先dp[0]=3没啥疑问，再看dp[1]是多少呢，由于3比2大，所以我们抢第一个房子的3，
    # 当前房子的2不抢，所以dp[1]=3，那么再来看dp[2]，由于不能抢相邻的，所以我们可以用再前面的一个的dp值加上当前的房间值，
    # 和当前房间的前面一个dp值比较，取较大值当做当前dp值，
    # 所以我们可以得到递推公式dp[i] = max(num[i] + dp[i - 2], dp[i - 1]),
    # 由此看出我们需要初始化dp[0]和dp[1]，其中dp[0]即为num[0]，dp[1]此时应该为max(num[0], num[1])
    def rob(self, nums):
        size = len(nums)
        dp = [0] * (size + 1)
        if size:
            dp[1] = nums[0]
        for i in range(2, size + 1):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1])
        return dp[size]

    #核心思想还是用DP，分别维护两个变量a和b，然后按奇偶分别来更新a和b，这样就可以保证组成最大和的数字不相邻
    def rob1(self, nums):
        size = len(nums)
        odd, even = 0, 0
        for i in range(size):
            if i % 2:
                odd = max(odd + nums[i], even)
            else:
                even = max(even + nums[i], odd)
        return max(odd, even)


    #dfs超时
    def rob2(self, nums):
        self.nums = nums
        self.l = len(nums)
        if self.l<1: return 0
        elif self.l<2: return nums[0]
        return max(self.dfs(0,self.nums[0]),self.dfs(1,self.nums[1]))

    def dfs(self,start,cur):
        f1 = self.dfs(start+2,cur+self.nums[start+2]) if start+2<self.l else cur
        f2 = self.dfs(start+3,cur+self.nums[start+3]) if start+3<self.l else cur
        return max(f1,f2)


s = Solution()
print(s.rob([3,1,2,7,9,13,11]))