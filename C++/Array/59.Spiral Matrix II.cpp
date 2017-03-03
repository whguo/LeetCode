/*
给出数字n，返回螺旋状的二维数组，元素从1到n^2。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if(n==0)    {vector<vector<int>> result;    return result;}
		vector<vector<int>> result(n,vector<int>(n));
        int m=--n,rowstart=0,colstart=0,num=1;
		while (rowstart<=m && colstart<=n)
		{
			for (int j = colstart; j <= n; ++j)
			{
				result[rowstart][j] = num++;
			}
			++rowstart;
			for (int i = rowstart; i <= m; ++i)
			{
				result[i][n] = num++;
			}
			--n;
			if(rowstart<=m)
			{
				for (int j = n; j >= colstart; --j)
				{
					result[m][j] = num++;
				}
			
			}
			--m;
			if(colstart<=n)
			{
				for (int i = m;i >= rowstart; --i)
				{
					result[i][colstart] = num++;
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
	vector<vector<int>> out= s.generateMatrix(5);
	for(int i=0; i < out.size(); ++i)
	{
		for(int j=0; j < out[i].size(); ++j)
		{
			cout<<out[i][j]<<"\t";
		}
		cout<<endl;
	}
}

