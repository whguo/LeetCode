/*
给出一个正数数组(没有重复数)和目标值，有多少种数组中的数构成的序列，它们的和是目标值。
例如：nums = [1, 2, 3]，target = 4。返回7。
(1, 1, 1, 1)(1, 1, 2)(1, 2, 1)
(1, 3)(2, 1, 1)(2, 2)(3, 1)
*/
/*
思路：target是数组中数的和，考虑如果只剩一个数就可以到达target，这个数可以是数组中的任意一个。
那么组成target的序列数comb[target] = sum(com[target-nums[i]])，
其中0 <= i < nums.length, 而且 target >= nums[i]。显然comb[0] = 1。
由此可以做出递归版本。但是递归超时，考虑DP。需要找出存储中间结果的方法。
dp[i]表示前面的计算结果，值-1为没计算过。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
        /*递归
        if(target == 0)	return 1;
        int result = 0;
        for(int i=0; i < nums.size(); ++i)
        {
        	if(target >= nums[i])
        		result += combinationSum4(nums,target-nums[i]);
        }
        return result;*/

        //dp
        int n = nums.size();
        vector<int>	dp(target+1);
        dp[0] = 1;
        for(int i=1; i <= target; ++i)
        {
        	for(int j=0; j < n; ++j)
        	{
        		if(i - nums[j] >= 0)
        			dp[i] += dp[i - nums[j]];
        	}
        }
        return dp[target];
    }
};
int main()
{
	Solution s;
	vector<int> nums{1,2,3};
	cout << s.combinationSum4(nums,4) <<endl;
}

