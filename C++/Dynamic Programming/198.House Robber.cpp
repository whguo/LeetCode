/*
抢劫一排房间，相邻的房间被抢会触发警报。
*/
/*
思路：当前最大为，抢前一个房子，或者抢前前一个加上当前这个。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if(n ==0 )	return 0;
		else if(n==1)	return nums[0];
        vector<int>	dp(n);
        dp[0] = nums[0], dp[1] = max(nums[0],nums[1]);
        for(int i=2; i < n; ++i)
        {
        	dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};
int main()
{
	Solution s;
	vector<int> nums{2,3,4,4};
	cout<<s.rob(nums)<<endl;
}

