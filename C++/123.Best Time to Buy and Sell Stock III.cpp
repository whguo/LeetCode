/*
最佳的购买和抛售股票的时机，最多买卖各两次，求最大收益。
而且同一天不能进行两次交易。
*/
/*
思路：动态规划。
 */

#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for(int i=0; i < prices.size(); ++i)
        {   
        	// Assume we only have 0 money at first
            release2 = max(release2, hold2+prices[i]);     // The maximum if we've just sold 2nd stock so far.
            hold2    = max(hold2, release1-prices[i]);  // The maximum if we've just buy  2nd stock so far.
            release1 = max(release1, hold1+prices[i]);     // The maximum if we've just sold 1nd stock so far.
            hold1    = max(hold1, -prices[i]);          // The maximum if we've just buy  1st stock so far. 
        }
        return release2;
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(9);
	nums.push_back(0);
	cout<<s.maxProfit(nums)<<endl;
}