/*
列出n对括号所有可能的排列方式（一对括号中左括号必须在右括号左边）。
*/
/*
思路：回溯法。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> result;
	int npublic;
	vector<string> generateParenthesis(int n) {
		npublic = n;
    	backtrack("",0,0);
    	return result;
    }

    void backtrack(string tmp,int open,int close)
    {
    	if(tmp.length()==2*npublic)
    	{
    		result.push_back(tmp);
    		return;
    	}
    	if(open<npublic)	backtrack(tmp+'(',open+1,close);
    	if(close<open)		backtrack(tmp+')',open,close+1);
    }

    //循环的方法：动态规划,把f都存下来。
    /*f(0): ""
	f(1): "("f(0)")"
	f(2): "("f(0)")"f(1), "("f(1)")"
	f(3): "("f(0)")"f(2), "("f(1)")"f(1), "("f(2)")"
	So f(n) = "("f(0)")"f(n-1) , "("f(1)")"f(n-2) "("f(2)")"f(n-3) ... "("f(i)")"f(n-1-i) ... "(f(n-1)")"
	*/
    vector<string> IterativegenerateParenthesis(int n) {
		vector<vector<string>>	myvec(1);
		myvec[0].push_back("");
		for(int i=1; i <= n; ++i)
		{
			vector<string> tmp;
			for(int j=0; j < i; ++j)
			{
				for(string first:myvec[j])
				{
					for(string second:myvec[i-1-j])
						tmp.push_back("("+first+")"+second);
				}
			}
			myvec.push_back(tmp);
		}
		return myvec.back();
    }
};

int main()
{
	Solution s;;
	vector<string> re = s.generateParenthesis(3);
	for(string str:re)
		cout<<str<<endl;
}

