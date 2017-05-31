/*
旋转有序数组，存在重复元素，寻找给定数的位置。
*/
/*
思路：先搞清楚数组当前结构，然后用给定数判断其位置。
重复数字的影响？连续相等数字，造成左右混淆。
[1,1,1,3,1],[1,3,1,1,1]不清楚3在中间数的左侧还是右侧
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
        int length = nums.size();
		if (length == 0)	return false;
		int left = 0, right = length - 1, mid;
		while(left < right)
		{
			mid = (left+right)/2;
			if(target==nums[mid])	return true;
			if(nums[left]>nums[mid])
			{
				if(nums[mid]<target && nums[left]>target)	left = mid+1;
				else left = mid+1;
			}
			else if(nums[left] < nums[mid])
			{
				if(nums[left]<=target && nums[mid]>target)	right = mid-1;
				else left = mid+1
			}
			else	++left;
			//如果left和mid相等，那么可以先让left加1，直到能够比较出大小，可以继续用二分法。
		}
		return nums[left]==target;
    }
};

int main()
{
	Solution s;
	//vector<int> nums{ 4, 5, 6, 7, 0, 0 , 1, 2, 3 };
	vector<int> nums{ 1, 3 , 1 , 1 , 1};
	cout<<s.search(nums,3)<<endl;
}

