/*
二维数组，中间有障碍1，空位置0，求从左上到右下有多少种路径（只能往下和往右移动）。
*/
/*
思路：后边的每个位置，如果是1（即障碍），则将该位置置为0，表示从前面到该位置的路径数是0
如果该位置是0，左加上。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	int m = obstacleGrid.size(),n;
    	if(m > 0)	n = obstacleGrid[0].size(); else return 0;
        vector<vector<int>> matrix(m,vector<int> (n));
        if(!obstacleGrid[0][0])	matrix[0][0] = 1; else return 0;
        for(int i=0; i < m; ++i)
        {
        	for(int j=0; j < n; ++j)
        	{
        		if(!obstacleGrid[i][j])
        		{
        			if(i > 0)	matrix[i][j] += matrix[i-1][j];
        			if(j > 0)	matrix[i][j] += matrix[i][j-1];
        		}
        		else
        			matrix[i][j] = 0;
        	}
        }
        return matrix[m-1][n-1];
    }
};
int main()
{
	Solution s;
	vector<vector<int>> grid{{0,1,0},{0,1,0},{0,0,0}};
	cout<<s.uniquePathsWithObstacles(grid)<<endl;
}

