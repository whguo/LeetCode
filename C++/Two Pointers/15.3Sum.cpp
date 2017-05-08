/*
求数组中的三个数和为target。
*/
/*
思路：两层循环，第一层遍历值，把重复的跳过。
第二层两个指针指头尾，target为第一层的相反数。
和大于target，尾向前，小于target，头向后。
每次移动都把重复值跳过。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
		int length = nums.size(), i, j, k;
		sort(nums.begin(), nums.end());
		for (k = 0; k < length - 2; ++k)
		{
			int target = -nums[k];
			i = k + 1, j = length - 1;
			while (i < j)
			{
				if (nums[i] + nums[j] == target)
					result.push_back(vector<int> {nums[k], nums[i], nums[j]});
				if (nums[i] + nums[j] < target)
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
	vector<int> nums{ 1, 0, -1, 0, -2, 2 };
	vector<vector<int>> out;
	out = s.threeSum(nums);
	for (int i = 0; i < out.size(); ++i)
	{
		for (int j = 0; j < out[i].size(); ++j)
		{
			cout << out[i][j] << "\t";
		}
		cout << endl;
	}
}

