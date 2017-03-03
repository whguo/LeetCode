/*
二维数组，从左上到右下有多少种路径（只能往下和往右移动）。
*/
/*
思路：第一列和第一行都是1，然后其余位置对左边和上边求和即可。。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
        vector<vector<int>> path(m,vector<int>(n,1));
        for(int i = 1; i < m; ++i)
        {
        	for(int j = 1; j < n; ++j)
        	{
        		path[i][j] = path[i-1][j]+path[i][j-1];
        	}
        }
        return path[m-1][n-1];
    }

};

int main()
{
	Solution s;
	cout<<s.minPathSum(4,5);
}

