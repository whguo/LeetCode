/*
求数组的一个子序列，乘积最大，返回乘积。
*/
/*
思路：碰到一个负数，那么大的数变小，小的数变大，所以让它俩换一下。
碰到零，当前最大最小都变成0。
 */

#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpro = nums[0];
        for(int i=1,curmax=maxpro,curmin=maxpro; i < nums.size(); ++i)
        {
        	if(nums[i]<0)	swap(curmin,curmax);
        	curmax = max(nums[i],curmax*nums[i]);
        	curmin = min(nums[i],curmin*nums[i]);
        	maxpro = max(maxpro,curmax);
        }
        return maxpro;
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(-1);
	nums.push_back(4);
	//nums.push_back(-7);
	//nums.push_back(0);
	//nums.push_back(1);
	//nums.push_back(2);
	cout<<s.maxProduct(nums)<<endl;
}