/*
最佳的购买和抛售股票的时机，最多买卖各一次，求最大收益。
*/
/*
思路：寻找后边的数与前面数的最大差。
 */

#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int length = prices.size();
    	if(length == 0)	return 0;
    	int maxpro = 0 , curmin = prices[0];
    	for(int i = 1; i < length; ++i)
    	{
    		maxpro = max(maxpro,prices[i]-curmin);
    		curmin = min(curmin,prices[i]);
    	}
    	return maxpro;
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(4);
	//nums.push_back(2);
	cout<<s.maxProfit(nums)<<endl;
}