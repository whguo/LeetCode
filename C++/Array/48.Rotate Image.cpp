/*
 n x n二维数组，顺时针旋转90度。
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
        for(int level=0; level < n/2; ++level)
        {
        	int m = n-1;
        	for(int i = level; i < m-level; ++i)
        	{
        		int temp = matrix[level][i];
        		matrix[level][i] = matrix[m-i][level];
        		matrix[m-i][level] = matrix[m-level][m-i];
        		matrix[m-level][m-i] = matrix[i][m-level];
        		matrix[i][m-level] = temp;
        	}
        }
    }
};

int main()
{
	Solution s;
	vector<vector<int>> nums{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	s.rotate(nums);
	for(int i=0 ; i < nums.size(); ++i)
	{
		for(int j=0; j < nums[i].size(); ++j)
		{
			cout<<nums[i][j]<<"\t";
		}
		cout<<endl;
	}
}

