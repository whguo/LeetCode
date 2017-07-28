/*
给出一个整数非空数组，判断是否能将该数组分成两个部分，使得这两个部分的和相同。
*/
/*
思路：先求和，得出和的一半。然后动态规划。
     因为分得的数组中不能出现重复元素，所以外层循环是本数组，内层是dp。
     如果是可以重复，顺序交换(参考题377)。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n:nums)	sum += n;
        if(sum & 1)		return false;
        vector<bool>	dp(sum/2+1,false);
    	dp[0] = true;
    	for(int n:nums)
    	{
    		for(int i=dp.size(); i > 0; --i)
    		{
    			if(i >= n)	dp[i] = dp[i] || dp[i-n];
    		}
    	}
    	return dp.back();
    }
};
int main()
{
	Solution s;
	vector<int> nums{1,5,11,5};
	cout << s.canPartition(nums) <<endl;
}

