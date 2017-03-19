/*
二维数组，1代表陆地，0代表水，有一个1组成的小岛，求小岛周长。
*/
/*
思路：每有一个陆地周长加4，每有一个相邻，周长减2。
 */
#include <iostream>
#include <vector> 
using namespace std;


class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int result = 0;
        for(int i=0; i < grid.size(); ++i)
        {
        	for(int j=0; j < grid[i].size(); ++j)
        	{
        		if(grid[i][j]==1)
        		{
        			result += 4;
        			if(i>0 && grid[i-1][j]==1)	result-=2;
        			if(j>0 && grid[i][j-1]==1)	result-=2;
        		}
        	}
        }
        return result;
    }
};
int main()
{
	Solution s;
	vector<vector<int>> grid{{0,1,0,0},{1,1,1,0},{0,1,1,0},{1,1,0,0}};
 	cout<<s.islandPerimeter(grid)<<endl;
}

