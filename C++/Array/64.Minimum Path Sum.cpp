/*
二维数组，找到一条路径使得从左上到右下和最小（只能往下和往右移动）。
*/
/*
思路：比较左边和上边的值，利用数组存下来到当前位置的最小值。
 */
#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
using namespace std;

class Solution {

	/*DFS方法太笨，超时。
public:
	vector<vector<int>> mygrid;
	int row;
	int col;
	int minsum;
public:
	int minPathSum(vector<vector<int>>& grid) {
        mygrid = grid,row = grid.size(),col = grid[0].size(),minsum=MAX_INT;
        return dfs(0,0);
    }
    int dfs(int i,int j)
    {
    	if(i==row && j==col)	return mygrid[i][j];
    	if(i<row  && j==col)
    		return mygrid[i][j]+dfs(i+1,j);
    	else if(i==row && j<col)
    		return mygrid[i][j]+dfs(i,j+1);
    	else
    		return mygrid[i][j]+min(dfs(i+1,j),dfs(i,j+1));
    }*/
public:
	int minPathSum(vector<vector<int>>& grid) {
        for(int i=0; i < grid.size(); ++i)
        {
        	for(int j=0; j < grid[i].size(); ++j)
        	{
        		if(i==0 && j>0)	grid[i][j] = grid[i][j]+grid[i][j-1];
        		else if(j==0 && i>0)	grid[i][j] = grid[i][j]+grid[i-1][j];
        		else if(i>0 && j>0)		grid[i][j] = grid[i][j]+min(grid[i-1][j],grid[i][j-1]);
        	}
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }

};

int main()
{
	Solution s;;
	vector<vector<int>> nums{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	cout<<s.minPathSum(nums);
}

