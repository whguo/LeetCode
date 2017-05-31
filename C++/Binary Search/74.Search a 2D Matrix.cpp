/*
在二维有序数组中寻找给定的数，每行数升序排列，
下一行的第一个大于上一行的最后一个。
*/
/*
思路：先用二分法找给定数应该所在的行，方法是如果小于这行的最后一个数，那么在该行。
注意此时，如果mid这行的最后一个数小于target，那么left=mid+1，
如果大于的话，不能让right=mid-1，而应该等于mid，
因为大于的话仍有可能在该行，而且mid是向下取整，不会导致死循环。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
		if(m==0 || matrix[0].size()==0)	return false;
        int left = 0,right = m-1, n = matrix[0].size()-1,mid,row;
        while(left < right)
        {
        	mid = (left+right)/2;
        	if(matrix[mid][n] == target)	return true;
        	else if(matrix[mid][n] < target)	left = mid+1;
        	else right = mid;
        }
        row = left , left = 0, right = n;
        while(left <= right)
        {
        	mid = (left+right)/2;
        	if(matrix[row][mid] == target)	return true;
        	else if(matrix[row][mid] < target)	left=mid+1;
        	else right = mid-1;
        }
        return false;
    }
};

int main()
{
	Solution s;
	vector<vector<int>> nums{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	//vector<vector<int>> nums{{1}};
	cout<<s.searchMatrix(nums,0)<<endl;
}

