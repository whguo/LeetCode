/*
有序二维数组，每行从左到右增大。下一行开头大于上一行末尾。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int length = matrix.size();
		if(length==0)	return false;
		if(matrix[0].size()==0)	return false;
        int left = 0,right = length-1,mid,row;
        while(left<right)
        {
        	mid = (left+right)/2;
        	if(matrix[mid][0]==target)	return true;
        	if(matrix[mid][0]>target) right = mid-1;
        	else	left = mid+1;		
        }
        if(matrix[left][0]==target)	return true;

        //二分完不确定是在哪行
        row = (matrix[left][0]<target)?left:left-1;

        //行减完有可能小于0
        if(row<0)	return false;
        left = 0 , right = matrix[0].size();
        while(left<=right)
        {
        	mid = (left+right)/2;
        	if(matrix[row][mid]==target)	return true;
        	if(matrix[row][mid]>target) right = mid-1;
        	else	left = mid+1;		
        }
        return false;
    }
};

int main()
{
	Solution s;;
	//vector<vector<int>> nums{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	vector<vector<int>> nums{{1}};
	cout<<s.searchMatrix(nums,0)<<endl;
}

