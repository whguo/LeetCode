/*
给出n+1个数，都在1到n之间。假设只有一个重复的元素（它可以出现多次），找到它。
不可以改变数组。O(1)的空间。小于O(n^2)的时间。
*/
/*
二分法+鸽笼原理：
二分枚举答案范围，使用鸽笼原理进行检验
根据鸽笼原理，给定n + 1个范围[1, n]的整数，其中一定存在数字出现至少两次。
假设枚举的数字为 n / 2：
遍历数组，若数组中不大于n / 2的数字个数超过n / 2，则可以确定[1, n /2]范围内一定有解，
否则可以确定解落在(n / 2, n]范围内。
小于O(n2)的运行时间复杂度可以联想到使用二分将其中的一个n化简为log n。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
        int low = 1 , high = nums.size()-1, mid , count;
    	while(low<=high)
    	{
    		mid = (low+high)>>1;
    		count = 0;
    		for(int i=0; i < nums.size(); ++i)
    		{
    			if(nums[i]<=mid)	count++;
    		}
    		if(count>mid)	high = mid-1;
    		else low = mid+1;
    	}
    	return low;
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,2,4,3,2};
	cout << s.findDuplicate(nums) << endl;
}

