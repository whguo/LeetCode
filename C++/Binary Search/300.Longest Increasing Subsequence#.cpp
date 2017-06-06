/*
返回数组中最长的增长子数组长度。
如：[10, 9, 2, 5, 3, 7, 101, 18]，最长的是[2, 3, 7, 101]，返回4
*/
/*
思路：创建一个数组tails，tails[i]代表所有长度为i+1的增长子数组中最小的末尾元素。
例如，nums = [4,5,6,3]。
长度为1的增长子数组为[4],[5],[6],[3]，末尾元素最小的是3，所以tails[0]=3。
长度为2的增长子数组为[4,5],[5,6]，末尾元素最小的是5，所以tails[1]=5。
长度为3的增长子数组为[4,5,6]，末尾元素最小的是6，所以tails[2]=6。
可以证明tails是一个递增的数组。
因此可以用二分法寻找需要更新的位置。
如果nums[x]比所有的tails大，那么在tails末尾增加nums[x]。
如果tails[i-1]<nums[x]<=tails[i]，更新tails[i]。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> tails(nums.size());;
		int size = 0;
		for(int x:nums)
		{
			int i = 0, j = size;
			while(i < j)
			{
				int m = (i + j)/2;
				if(tails[m]<x)	i = m + 1;
				else j = m;
			}
			tails[i] = x;
			if(i == size)	++size;
		}
		return size;
    }
};

int main()
{
	Solution s;
	vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
	cout << s.lengthOfLIS(nums) << endl;
}

