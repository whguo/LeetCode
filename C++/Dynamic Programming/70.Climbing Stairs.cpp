/*
爬n级台阶，每次可以爬1级或者2级。问一共有多少种爬法?
*/
/*
思路：就是斐波那契数列。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	/*用数组
    	if(n <= 2)	return n;
        vector<int> dp(n);
        dp[0] = 1, dp[1] = 2;
        for(int i=2; i < n; ++i)
        	dp[i] = dp[i-1] + dp[i-2];
        return dp[n-1];*/

    	//用两个辅助变量，节省空间
    	if(n <= 2)	return n;
        int one_step_before = 2 , two_steps_before = 1, all_ways = 0;   
    	for(int i=2; i<n; i++)
    	{
    		all_ways = one_step_before + two_steps_before;
    		two_steps_before = one_step_before;
        	one_step_before = all_ways;
    	}
    	return all_ways;
    }
};
int main()
{
	Solution s;
	cout<<s.climbStairs(10)<<endl;
}

