/*
求最大连续子串和。
*/
/*
思路：根据累计和是否小于0，来判断是否将累计和变为当前数。
 */

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
        int cursum = 0 , maxsum = INT_MIN;
        for(int i=0; i < nums.size(); ++i)
        {
        	if(cursum < 0)	cursum = nums[i];
        	else cursum += nums[i];
        	if(maxsum < cursum)   maxsum = cursum;
        }
        return maxsum;
    }
};

int main()
{
	Solution s;
	vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
	cout<<s.maxSubArray(nums)<<endl;
}

