/*
等差数列至少包含3个数，且间隔相同。
求给定数组中等差数列的个数。
eg:[1,2,3,4] 返回3
[1,2,3],[2,3,4],[1,2,3,4]
*/
/*
思路：动态规划。
要额外记录差值连续出现的次数。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int n = A.size();
		if(n < 3)	return 0;
        vector<int> dp(n),count(n);//count代表差连续出现的次数
        dp[1] = dp[0] = 0;
        count[0] = 0, count[1] = 1;
        for(int i=2; i < n; ++i)
        {
        	if(A[i]-A[i-1]==A[i-1]-A[i-2])
        	{
        		dp[i] = dp[i-1]+1;
        		count[i] = count[i-1]+1;
        		if(count[i]-count[i-2]==2)
        		{
        			dp[i] += count[i-2];
        		}
        	}
        	else
        	{
        		dp[i] = dp[i-1];
        		count[i] = 1;
        	}
        }
        return dp[n-1];
    }
};
int main()
{
	Solution s;
	vector<int> nums{1,2,3,4,5,6,7};
	cout << s.numberOfArithmeticSlices(nums) << endl;
}

