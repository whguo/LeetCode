/*
一个数组(无重复元素)，一个目标值，返回所有数组中的元素和为目标值的组合，每个元素只能用一次。
*/
/*
思路：DFS搜索。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	sort(candidates.begin(),candidates.end());
    	vector<int> tmp;
        helpCombinationSum(candidates,tmp,0,target);
        return result;
    }
    void helpCombinationSum(vector<int>& candidates,vector<int>& tmp,int start,int target)
    {
    	if(target==0)	result.push_back(tmp),return;
    	for(int i=start; i < candidates.size(); ++i)
    	{
    		if(candidates[i] > target)	return;
    		//i>start是精髓，防止重复，不可以替换成tmp.size()==0，因为重复不一定是第一个。
    		if(i>0 && candidates[i-1]==candidates[i] && i>start)	continue;	
    		tmp.push_back(candidates[i]);
    		helpCombinationSum(candidates,tmp,i+1,target-candidates[i]);
    		tmp.pop_back();
    	}
    }
};
int main()
{
	Solution s;
	vector<int>	candidates{10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> out = s.combinationSum2(candidates,8);
    for(auto vec:out)
    {
    	for(int n:vec)
    		cout<<n<<" ";
    	cout<<endl;
    }
}

