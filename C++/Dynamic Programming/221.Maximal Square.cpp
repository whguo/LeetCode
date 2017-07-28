/*
给出二维数组包含0和1，找出1构成的最大的正方形，并返回其面积。
*/
/*
思路：如果当前值为'0'，那么dp为0，如果为1，那么dp值为左边，上边，左上角三个dp值的最小加1。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(),n;
        if(m==0)	return 0;
        else n = matrix[0].size();

        int result = 0;
        vector<vector<int>> dp(m,vector<int> (n));
        for(int i=0; i < m; ++i)	
        {
        	if(matrix[i][0] == '1')
        	{
        		dp[i][0] = 1;
        		result = 1;
        	}
        }
        for(int j=0; j < n; ++j)	
        {
        	if(matrix[0][j] == '1')
        	{
        		dp[0][j] = 1;
        		result = 1;
        	}
        }
        for(int i=1; i < m; ++i)
        {
        	for(int j=1; j < n; ++j)
        	{
        		if(matrix[i][j] == '0')	dp[i][j] = 0;
        		else
        		{
        			dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
        			if(dp[i][j] > result)	result = dp[i][j];
        		}
        	}
        }
        return result;
    }
};
int main()
{
	Solution s;
	vector<vector<char>> matrix{{'1','0','1','0','0'},{'1','0','1','1','1'},
								{'1','1','1','1','1'},{'1','0','0','1','0'}};
	cout<<s.maximalSquare(matrix)<<endl;
}

