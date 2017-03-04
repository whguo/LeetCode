/*
一个有序数组，里面有重复元素。
返回给定数在数组中的位置范围。如果不在，[-1,-1]。
要求时间O(logN)。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     vector<int> searchRange(vector<int>& nums, int target) {
     	vector<int> result{-1,-1};
     	if(nums.size()==0)	return result;
     	int left = 0,right = nums.size()-1,mid;
     	while(left<right)
     	{
     		mid = (left+right)/2;
     		if(nums[mid]==target)
     		{
     			left = mid;		break;
     		}
     		if(nums[mid]>target)	right = mid-1;
     		else	left = mid+1;
     	}
     	if(nums[left]!=target)	return result;
     	int i = left;
     	while(i>=0 && target==nums[i])	--i;
     	result[0] = i+1,i = left;
     	while(i<nums.size() && target==nums[i])	 ++i;
     	result[1] = i-1;
     	return result;
     }
};

int main()
{
	Solution s;
	vector<int> nums{5, 7, 7, 8, 8, 10};
	nums = s.searchRange(nums, 3);
	cout<<nums[0]<<","<<nums[1]<<endl;
}

