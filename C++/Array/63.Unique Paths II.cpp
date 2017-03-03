/*
二维数组，中间有障碍1，空位置0，求从左上到右下有多少种路径（只能往下和往右移动）。
*/
/*
思路：左上开始，一个位置是1，则将它置为0，如果是0，则置为1。
后边的每个位置，如果是1（即障碍），则将该位置置为0，表示从前面到该位置的路径数是0
如果该位置是0，左加上。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if(obstacleGrid[0][0]==1)	return 0;
        for(int i=0; i < obstacleGrid.size(); ++i)
        {
        	for(int j=0; j < obstacleGrid[0].size(); ++j)
        	{
        		if(obstacleGrid[i][j]==0)
        		{
        			if(i==0 && j==0)	obstacleGrid[i][j] = 1;
        			if(j>0)	obstacleGrid[i][j] = obstacleGrid[i][j-1];
        			if(i>0)		obstacleGrid[i][j] += obstacleGrid[i-1][j];
        		}
        		else
        		{
        			obstacleGrid[i][j] = 0;
        		}
        	}
        }
        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};

int main()
{
	Solution s;
	vector<vector<int>> grid{{0,1,0},{0,1,0},{0,0,0}};
	cout<<s.uniquePathsWithObstacles(grid);
}

