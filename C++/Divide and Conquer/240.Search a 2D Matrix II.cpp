/*
在二维数组中查找某数。
数组每行升序排列，每列升序排列。
*/
/*
思路：从右上角开始，如果大于target，那么不可能在该列j-1。
如果小于target，那么不可能在该行，i+1。
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n;
		if(m==0 || (n=matrix[0].size())==0)	return false;
        int i = 0,j = n-1;
        while(i<m && j>=0)
        {
        	if(matrix[i][j]==target)	return true;
        	else if(matrix[i][j]>target)
        		--j;
        	else ++i;
        }
        return false;
    }
};

int main()
{
	Solution s;
	vector<vector<int>> nums{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22}{10,13,14,17,24}};
	cout<<s.searchMatrix(nums,0)<<endl;
}

