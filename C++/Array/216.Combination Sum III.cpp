/*
找到所有的k个数，加起来为n，只能使用1到9
*/
/*
思路:DFS
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector <int>> result;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;
        dfs(k,n,0,current);    
        return result;
    }

    void dfs(int k,int n,int low,vector<int> current)
    {
    	if(n<=0)	return;
    	if(k==1)
    	{
    		if(n<=9 && n>low)
    		{
    			current.push_back(n);
    			result.push_back(current);
    			current.pop_back();
    		}
    		return;
    	}
    	else
    	{
    		for(int i=low+1; i < 9; ++i)
    		{
    			current.push_back(i);
    			dfs(k-1,n-i,i,current);
    			current.pop_back();
    		}
    	}
    }
};

int main()
{
	Solution s;
	vector<vector<int>> nums;
	nums = s.combinationSum3(3,9);
	for(int i=0; i<nums.size(); ++i)
	{
		for(int j=0; j<nums[i].size(); ++j)
		{
			cout<<nums[i][j]<<",";
		}
		cout<<endl;
	}
}