/*
返回数组中最长的增长子数组长度。
如：[10, 9, 2, 5, 3, 7, 101, 18]，最长的是[2, 3, 7, 101]，返回4
*/
/*
思路：动态规划。dp[i]代表到下标i为止最长的增长子数组长度。
显然dp[0] = 1。
求每个dp[i]需要遍历i之前的每个数nums[j]，找到比nums[i]小的数中，dp[j]最大的。
然后dp[i] = dp[j]+1。
如果前面没有比nums[i]小的数，那么dp[i]为1。
每次更新dp[i]后，更新最大长度。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if(nums.size()==0)	return 0;
        vector<int>   dp(nums.size(),1);
        int result = 1;
        for(int i=1; i < nums.size(); ++i)
        {
        	int maxsub = 0;
        	for(int j=i-1; j >=0; --j)
        	{
        		if(nums[j] < nums[i])
        			maxsub = max(maxsub,dp[j]);
        	}
        	dp[i] = (maxsub==0)? 1:maxsub+1;
        	result = max(result,dp[i]);
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
	cout << s.lengthOfLIS(nums) << endl;
}

