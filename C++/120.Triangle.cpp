/*
一个三角从上到下的一条路径，求路径数值之和(每移动一行，只能跳到相邻列)
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
最小路径2+3+5+1=11
*/
/*
思路：DFS（超时）。
 */

#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
using namespace std;

class Solution {

public:
	/*DFS方法
    int minimumTotal(vector<vector<int>>& triangle) {
    	if(triangle.size()==1)	return triangle[0][0];
    	return dfs(1,0,triangle)+triangle[0][0];
    }

    int dfs(int row,int column,vector<vector<int>>& mytriangle)
    {
    	if(row==mytriangle.size()-1)
    	{
    		if(column+1<mytriangle[row].size())
    			return min(mytriangle[row][column],mytriangle[row][column+1]);
    	}
    	else
    	{
    		return min(dfs(row+1,column,mytriangle)+mytriangle[row][column],dfs(row+1,column+1,mytriangle)+mytriangle[row][column+1]);
    	}
    }*/

    int minimumTotal(vector<vector<int>>& triangle) {
    	
    }
};

int main()
{
	Solution s;
	vector<vector<int>> nums;
	vector<int> num1{2};
	vector<int> num2{3,4};
	vector<int> num3{6,5,7};
	vector<int> num4{4,1,8,3};
	nums.push_back(num1);
	nums.push_back(num2);
	nums.push_back(num3);
	nums.push_back(num4);
	cout<<s.minimumTotal(nums)<<endl;
}