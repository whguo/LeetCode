/*
求数组中的三个数和最接近target。返回这三个数的和。
*/
/*
思路：借用3Sum的方法。多一层循环，每一层把重复的跳过。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <windef.h>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int length = nums.size(), i, j, k,result,dis = INT_MAX,tmp;
		sort(nums.begin(), nums.end());
		for (k = 0; k < length - 2; ++k)
		{
			int tar = target-nums[k];
			i = k + 1, j = length - 1;
			while (i < j)
			{
				if (nums[i] + nums[j] == tar)	return target;
				tmp = fabs(nums[i] + nums[j]-tar);
				if(tmp<dis)
				{
					dis = tmp;
					result = nums[i] + nums[j] + nums[k];
				}
				if (nums[i] + nums[j] < tar)
				{
					++i;
					while (nums[i - 1] == nums[i]) ++i;
				}
				else
				{
					--j;
					while (j < length - 1 && nums[j + 1] == nums[j]) --j;
				}
			}
			while (nums[k] == nums[k + 1]) ++k;
		}
		return result;
	}

};

int main()
{
	Solution s;
	vector<int> nums{-1,2,1,-4};
	cout<<s.threeSumClosest(nums,1)<<endl;
}

