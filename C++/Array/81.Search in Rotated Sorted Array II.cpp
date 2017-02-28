/*
有序数组（可能有重复数字），左右移动某些位，在数组中寻找给定数。
*/
/*
思路：先搞清楚数组当前结构，然后用给定数判断其位置。
重复数字的影响？连续相等数字，造成左右混淆。
[1,1,1,3,1],[1,3,1,1,1]不清楚3在中间数的左侧还是右侧
 */
#include <iostream>
#include <vector>
#include <algorithm>
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
				if(target>=nums[left] || target<nums[mid])	right = mid-1;
				else left = mid+1;
			}
			else if(nums[left]<nums[mid])
			{
				if(target>nums[mid] || target<nums[left])	left = mid+1;
				else right = mid-1;
			}
			else
			{
				/*先没必要一个一个找，先挪一个，如果可以比较出来大小，就可以继续二分。
				for(int i = left; i<=right;++i)
				{
					if(nums[i]==target)	return true;
				}
				return false;*/
				++left;
			}
		}
		return (nums[left]==target)?true:false;
	}
};

int main()
{
	Solution s;
	//vector<int> nums{ 4, 5, 6, 7, 0, 0 , 1, 2, 3 };
	vector<int> nums{ 1, 3 , 1 , 1 , 1};
	cout<<s.search(nums, 3)<<endl;
}

