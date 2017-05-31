/*
旋转有序数组，无重复元素，找出最小数。
*/
/*
思路：如果nums[left]<nums[right],那么这一段有序，直接返回nums[left]。
否则，这一段是旋转过的，那么判断nums[left]和nums[mid]的关系即可确定向哪边移动。
当nums[mid]<nums[left]时，最小值有可能是nums[mid]，所以right=mid，而不是mid-1。
而且由于整数向下取整，这样不会死循环。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0, right = nums.size() - 1, mid;
		while(left < right)
		{
			mid = (left+right)/2;
			if(nums[left]<nums[right])	return nums[left];
			else
			{
				if(nums[mid]>=nums[left])	left=mid+1;
				else right = mid;	
			}
		}
		return nums[left];
    }
};

int main()
{
	Solution s;
	vector<int> nums{ 4, 5, 6, 7, 0 , 1, 2, 3 };
	cout<<s.findMin(nums)<<endl;
}

