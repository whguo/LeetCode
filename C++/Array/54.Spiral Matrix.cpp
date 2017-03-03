/*
返回二维数组的螺旋形态。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
        if(m==0)    
        	{vector<int> re;    return re;}
        int n = matrix[0].size(),pos=0,rowstart=0,colstart=0;
		vector<int> result(m--*n--);
		while (rowstart<=m && colstart<=n)
		{
			for (int j = colstart; j <= n; ++j)
			{
				result[pos++] = matrix[rowstart][j];
			}
			++rowstart;
			for (int i = rowstart; i <= m; ++i)
			{
				result[pos++] = matrix[i][n];
			}
			--n;
			if(rowstart<=m)//比如只有1列的情形，如果不判断会多写一列
			{
				for (int j = n; j >= colstart; --j)
				{
					result[pos++] = matrix[m][j];
				}
			
			}
			--m;
			if(colstart<=n)
			{
				for (int i = m;i >= rowstart; --i)
				{
					result[pos++] = matrix[i][colstart];
				}
			}
			++colstart;
		}
		return result;  
    }
};

int main()
{
	Solution s;
	vector<vector<int>> matrix{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, {13,14,15,16} };
	//vector<vector<int>> matrix{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	//vector<vector<int>> matrix{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 }, { 9, 10 }, {11,12} };
	//vector<vector<int>> matrix{ {1,2,3,4,5,6,7,8} };
	vector<int> out;
	out = s.spiralOrder(matrix);
	for(int i=0; i < out.size(); ++i)
	{
		cout<<out[i]<<endl;
	}
}

