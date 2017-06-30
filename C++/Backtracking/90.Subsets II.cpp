/*
给出数组可能包含重复元素，求出它的所有子集(不能有重复)。
*/
/*
思路：DFS递归。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> result;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>	tmp;
        helpSubsetsWithDup(nums,0,tmp);
        return result;
    }
    void helpSubsetsWithDup(vector<int>& nums,int start,vector<int>& tmp)
    {
    	result.push_back(tmp);
    	for(int i=start; i < nums.size(); ++i)
    	{
    		if(i && i!=start && nums[i]==nums[i-1])	continue;
    		tmp.push_back(nums[i]);
    		helpSubsetsWithDup(nums,i+1,tmp);
    		tmp.pop_back();
    	}
    }
};
int main()
{
	Solution s;
    vector<int> nums{1,2,2};
	vector<vector<int>> out = s.subsetsWithDup(nums);
	for(auto vec:out)
	{
		for(int n:vec)
			cout<<n<<" ";
		cout<<endl;
	}
}

