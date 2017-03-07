/*
求数组中的四个数和为target。
*/
/*
思路：DFS超时。
借用3Sum的方法。多一层循环，每一层把重复的跳过。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		int length = nums.size(), i, j, k, p;
		sort(nums.begin(), nums.end());
		for (p = 0; p < length - 3; ++p)
		{
			for (k = p+1; k < length - 2; ++k)
			{
				int tar = target-nums[k]-nums[p];
				i = k + 1, j = length - 1;
				while (i < j)
				{
					if (nums[i] + nums[j] == tar)
						result.push_back(vector<int> {nums[p],nums[k], nums[i], nums[j]});
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
			while (nums[p] == nums[p + 1]) ++p;
		}
		return result;
	}

};

int main()
{
	Solution s;
	vector<int> nums{ 1, 0, -1, 0, -2, 2 };
	vector<vector<int>> out;
	out = s.fourSum(nums, 0);
	for (int i = 0; i < out.size(); ++i)
	{
		for (int j = 0; j < out[i].size(); ++j)
		{
			cout << out[i][j] << "\t";
		}
		cout << endl;
	}
}

