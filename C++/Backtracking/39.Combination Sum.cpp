/*
一个数组(无重复元素)，一个目标值，返回所有数组中的元素和为目标值的组合，可以有重复。
*/
/*
思路：DFS搜索。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	vector<int> tmp;
        helpCombinationSum(candidates,tmp,0,target);
        return result;
    }
    void helpCombinationSum(vector<int>& candidates,vector<int>& tmp,int start,int target)
    {
    	for(int i=start; i < candidates.size(); ++i)
    	{
    		if(candidates[i] < target)
    		{
    			tmp.push_back(candidates[i]);
    			helpCombinationSum(candidates,tmp,i,target-candidates[i]);
    			tmp.pop_back();
    		}
    		else if(candidates[i] == target)
    		{
    			tmp.push_back(candidates[i]);
    			result.push_back(tmp);
    			tmp.pop_back();
    		}
    	}
    }
};
int main()
{
	Solution s;
	vector<int>	candidates{4,2,8};
    vector<vector<int>> out = s.combinationSum(candidates,8);
    for(auto vec:out)
    {
    	for(int n:vec)
    		cout<<n<<" ";
    	cout<<endl;
    }
}

