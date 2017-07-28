/*
求连续最长子数组的乘积最大值
*/
/*
思路：用两个变量记录到当前位置的最大和最小乘积。
碰到一个负数，那么大的数变小，小的数变大，所以让它俩换一下。
而更新当前最大最小分别为当前数与累计积的大小比较。
 */
#include <iostream>
#include <vector>
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
	vector<int> nums{2,3,-2,4};
	cout<<s.maxProduct(nums)<<endl;
}

