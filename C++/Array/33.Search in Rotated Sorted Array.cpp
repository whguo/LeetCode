/*
有序数组（没有重复数字），左右移动某些位，在数组中寻找给定数。
*/
/*
思路：先搞清楚数组当前结构，然后用给定数判断其位置。
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int length = nums.size();
		if (length == 0)	return -1;
		int left = 0, right = length - 1, mid;
		/*
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (target == nums[mid])	return mid;
			//中间数大于两边数
			if (nums[mid] >= nums[left] && nums[mid] >= nums[right])
			{
				if (target>nums[mid] || target <= nums[right])	left = mid + 1;
				else 		right = mid - 1;	
			}
			//中间数大于左边小于右边
			else if (nums[mid] >= nums[left] && nums[mid] <= nums[right])
			{
				if (target>nums[mid])	left = mid + 1;
				else right = mid - 1;
			}
			//中间数小于两边数
			else if (nums[mid] <= nums[left] && nums[mid] <= nums[right])
			{
				if (target<nums[mid] || target >= nums[left])	right = mid - 1;
				else 	left = mid + 1;   
			}
		}
		return -1;*/

		//不用像上边一样复杂，这个不是寻找最小数，所以比较一下中间数和左边数就可以大致确定数组结构
		while (left < right)
		{
			mid = (left + right) / 2;
			if (target == nums[mid])	return mid;
			if (nums[left]>nums[mid])
			{
				if (target >= nums[left] || target<nums[mid])	right = mid - 1;
				else left = mid + 1;
			}
			else
			{
				if (target>nums[mid] || target<nums[left])	left = mid + 1;
				else right = mid - 1;
			}
		}
		return (nums[left] == target) ? left : -1;
	}
};

int main()
{
	Solution s;
	vector<int> nums{ 4, 5, 6, 7, 0, 1, 2, 3 };
	//vector<int> nums{ 1, 3 };
	cout<<s.search(nums, 0)<<endl;
}

