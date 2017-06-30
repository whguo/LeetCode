/*
求出n个数中找出k个的所有组合。
*/
/*
思路：DFS递归。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> result;
public:
    vector<vector<int>> combine(int n, int k) {
    	vector<int> tmp;
        helpCombine(tmp,1,n,k);
        return result;
    }
    void helpCombine(vector<int>& tmp,int start,int n,int k)
    {
    	if(k == 0)
    	{
    		result.push_back(tmp);
    		return;
    	}
    	for(int i=start; i <= n; ++i)
    	{
    		tmp.push_back(i);
    		helpCombine(tmp,i+1,n,k-1);
    		tmp.pop_back();
    	}
    }
};
int main()
{
	Solution s;
    vector<vector<int>> out = s.combine(4,3);
    for(auto vec:out)
    {
    	for(int n:vec)
    		cout<<n<<" ";
    	cout<<endl;
    }
}

