/*
给一个二维数组，如果某个元素为0，将其行和列的数都设置为0。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int col0 = 1,row = matrix.size(),col = matrix[0].size();
        for(int i=0; i < row; ++i)
        {
        	if(matrix[i][0]==0)		col0=0;
        	for (int j = 1; j < col; ++j)
        	{
        		if(matrix[i][j]==0)
        		{
        			matrix[i][0] = 0;
        			matrix[0][j] = 0;
        		}
        	}
        }

        for(int i=row-1; i >=0  ; --i)
        {
        	for (int j = col-1; j >0 ; --j)
        	{
        		if(matrix[i][0]==0 || matrix[0][j]==0)		matrix[i][j] = 0;
        	}
        	if(col0==0)		matrix[i][0]=0;
        }
    }
};

int main()
{
	Solution s;;
	//vector<vector<int>> nums{{1,3,0,7},{10,11,16,20},{23,30,34,50}};
	//vector<vector<int>> nums{{1,1,1},{0,1,2}};
	vector<vector<int>> nums{{-4,-2147483648,6,-7,0},{-8,6,-8,-6,0},{2147483647,2,-9,-6,-10}};
	s.setZeroes(nums);
	for(int i=0 ; i < nums.size(); ++i)
	{
		for(int j=0; j < nums[0].size(); ++j)
		{
			cout<<nums[i][j]<<"\t";
		}
		cout<<endl;
	}
}

