/*
求数组的一个子数组，和最大。
*/
/*
思路：用前面的最大和加当前数，与当前数比较，大的作为最大和。
 */

#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
#include <limits.h>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
        int largestsum = INT_MIN,current;
        if(nums.size()==0)	return largestsum;
        largestsum = current = nums[0];
        for(int i=1; i < nums.size(); ++i)
        {
        	current = max(nums[i],current+nums[i]);
        	largestsum = max(current,largestsum);
        }
    	return largestsum;
    }
};

int main()
{
	Solution s;
	vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
	cout<<s.maxSubArray(nums)<<endl;
}

