/*
给出数n，猜1到n之间的数，每猜一次告诉是大了还是小了。猜错一次，要付该数对应的钱。
问最多需要付多少钱才能保证猜对这个数。
*/
/*
思路：dp[i][j]表示猜出范围[i, j]的数字需要花费的最少金额。
状态转移方程：dp[i][j] = min(k + max(dp[i][k - 1], dp[k + 1][j]))
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int getMoneyAmount(int n) {
        vector<vector<int>>	dp(n+1,vector<int> (n+1));
        for(int gap=1; gap < n; ++gap)
        {
        	for(int low=1; low < n+1-gap; ++low)
        	{
        		int high = low+gap;
        		dp[low][high] = INT_MAX;
        		for(int i=low; i < high; ++i)
        			dp[low][high] = min(dp[low][high],i + max(dp[low][i-1], dp[i+1][high]));
        	}
        }
        return dp[1][n];
    }
};
int main()
{
	Solution s;
	cout << s.getMoneyAmount(50) <<endl;
}

