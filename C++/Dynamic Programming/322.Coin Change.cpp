/*
给出几个硬币的面值，问最少用几个硬币可以凑成给定的数额。
凑不成则返回-1。
*/
/*
思路：转移方程为dp[i] = min(dp[i],dp[i-coins[j]]+1)。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
        int amountplus = amount + 1;
        vector<int> dp(amountplus,amountplus);
        dp[0] = 0;
        for(int i=1; i < amountplus; ++i)
        {
        	for(int coin:coins)
        	{
        		if(coin <= i)
        			dp[i] = min(dp[i],dp[i-coin]+1);
        	}
        }
        return (dp[amount] == amountplus)? -1:dp[amount];
    }
};
int main()
{
	Solution s;
	vector<int> coins{1,2,5};
	cout<<s.coinChange(coins,11)<<endl;    
}

