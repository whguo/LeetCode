/*
找出所有的k个数，加起来等于n。数只能是1--9的，且每个只能用一次。
*/
/*
思路：DFS递归。注意数的边界，需要小于10，而且需要小于等于剩余值除以剩余数的个数(适时剪枝)。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    	vector<int> tmp;
    	helpCombinationSum3(1,k,n,tmp);
        return result;
    }
    void helpCombinationSum3(int start,int k,int left,vector<int>& tmp)
    {
    	if(tmp.size() == k)
    	{
    		if(left==0)	result.push_back(tmp);
    		return;
    	}
    	int boundary = left/(k-tmp.size());
    	for(int i=start; i<10 && i <= boundary; ++i)
    	{
    		if (i > left)	return;
    		tmp.push_back(i);
    		helpCombinationSum3(i+1,k,left-i,tmp);
    		tmp.pop_back();
    	}
    }
};
int main()
{
	Solution s;
	vector<vector<int>> out = s.combinationSum3(3,9);
	for(auto vec:out)
	{
		for(int n:vec)
			cout<<n<<" ";
		cout<<endl;
	}
}

