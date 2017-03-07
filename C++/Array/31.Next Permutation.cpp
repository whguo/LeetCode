/*
一个数组表示一个多位数，返回下一个比它大的数。
若最大，返回最小的。
*/
/*
思路：先找到非逆序数，然后从后开始找比前面数大的数，换一下位置，然后颠倒位置。
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
     void nextPermutation(vector<int>& nums) {
        int length = nums.size()-1;
        int i = length,j = length;
        while(i>0 && nums[i-1]>=nums[i])
        {
        	--i;
        }
        if(0 == i)
        {
        	reverse(nums.begin(),nums.end());
        }
        else
        {
        	--i;
        	while(j>i && nums[j]<=nums[i])	--j;
        	swap(nums[i],nums[j]);
        	reverse(nums.begin()+i+1,nums.end());
        }
    }
};

int main()
{
	Solution s;
	vector<int> nums{5, 7, 2, 1};
	s.nextPermutation(nums);
	for(int i=0; i < nums.size(); ++i)
	{
		cout<<nums[i]<<endl;
	}
}

