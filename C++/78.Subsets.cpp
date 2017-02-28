/*
给出一个数组（不包含重复数字），求所有子集，不能包含重复的。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>>	result;
	vector<int> mynums;
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		int length = nums.size();
		if (length == 0)		return result;
		mynums = nums;
		sort(mynums.begin(), mynums.end());
		vector<int> empty(0);
		result.push_back(empty);
		for (int i = 1; i <= length; ++i)
		{
			vector<int> temp(i);
			dfs(temp, 0, 0, i);
		}
		return result;
	}
	void dfs(vector<int>& tmp, int index, int cur, int len)
	{
		if (index +len-cur>mynums.size())	return;
		if (cur == len)
		{	
			result.push_back(tmp);
		}
		else
		{
			for (int i = index; i < mynums.size(); ++i)
			{
				tmp[cur] = mynums[i];
				dfs(tmp, i+1, cur + 1, len);
			}
		}
	}
};

int main()
{
	Solution s;
	vector<int> nums{ 1, 2, 2 };
	vector<vector<int>> out = s.subsetsWithDup(nums);
	for (int i = 0; i < out.size(); ++i)
	{
		for (int j = 0; j < out[i].size(); ++j)
		{
			cout << out[i][j] << "\t";
		}
		cout << endl;
	}
}

