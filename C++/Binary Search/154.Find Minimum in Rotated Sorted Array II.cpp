/*
旋转有序数组，有重复元素，找出最小数。
*/
/*
思路：如果 nums[left]<nums[right]，那么这一段有序，最小为 nums[left]。
     如果 nums[left]>nums[right]，那么这一段是旋转过的有序数组，
     可以继续比较 nums[mid]与 nums[left]的关系，然后确定移动的方向。
     如果 nums[mid]>=nums[left]时，由于 nums[right]已经小于 nums[left]，最小值一定在mid的右边。
     否则，right=mid，因为最小有可能在mid位置。而且mid是向下取整，不会导致死循环。
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
			else if(nums[left]>nums[right])
			{
				if(nums[mid]>=nums[left])	left = mid+1;
				else right = mid;
			}
			else	++left;
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

