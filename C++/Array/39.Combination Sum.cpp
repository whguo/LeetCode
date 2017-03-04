/*
一个数组，一个目标值，返回所有数组中的元素和为目标值的组合，可以有重复。
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a < b;
}

class Solution {
public:
	vector<int> mycandidates;
	int mytarget;
	vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        mycandidates = candidates, mytarget = target;
        sort(mycandidates.begin(), mycandidates.end(), cmp);
		vector<int> empty;
		dfs(0, 0, empty);
		return result;
	}
	void dfs(int index, int current, vector<int> tmp)
	{
		int tmpcur;
		for (int i = index; i < mycandidates.size(); ++i)
		{
			tmpcur = current + mycandidates[i];
			if (tmpcur == mytarget)
			{
				tmp.push_back(mycandidates[i]);
				result.push_back(tmp);
				return;
			}
			else if (tmpcur<mytarget)
			{
				tmp.push_back(mycandidates[i]);
				dfs(i, tmpcur, tmp);
				tmp.pop_back();
			}
			else
			{
				return;
			}
		}
	}
};

int main()
{
	Solution s;
	vector<int> nums{ 2, 3, 6, 7 };
	vector<vector<int>> out;
	out = s.combinationSum(nums, 7);
	for (int i = 0; i < out.size(); ++i)
	{
		for (int j = 0; j < out[i].size(); ++j)
		{
			cout << out[i][j] << "\t";
		}
		cout << endl;
	}
}

