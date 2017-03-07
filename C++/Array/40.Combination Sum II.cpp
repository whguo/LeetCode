/*
一个数组，一个目标值，返回所有数组中的元素和为目标值的组合。
不能重复使用数组中的数，但是数组中本身可以有重复的数。
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> mycandidates;
	int mytarget;
	vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        mycandidates = candidates, mytarget = target;
        sort(mycandidates.begin(), mycandidates.end());
		vector<int> empty;
		dfs(-1, 0, empty);
		return result;
	}
	void dfs(int index, int current, vector<int> tmp)
	{
		int tmpcur;
		for (int i = index+1; i < mycandidates.size(); ++i)
		{
			tmpcur = current + mycandidates[i];
			if (tmpcur == mytarget)
			{
				tmp.push_back(mycandidates[i]);
				for(int j = 0; j < result.size(); ++j)
				{
					if(result[j]==tmp)	return;
				}
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
	vector<int> nums{ 10, 1, 2, 7, 6, 1, 5 };
	vector<vector<int>> out;
	out = s.combinationSum2(nums, 8);
	for (int i = 0; i < out.size(); ++i)
	{
		for (int j = 0; j < out[i].size(); ++j)
		{
			cout << out[i][j] << "\t";
		}
		cout << endl;
	}
}

