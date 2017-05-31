/*
向排序数组中插入一个数，找出应该插入的位置。
*/
/*
思路：二分注意循环退出条件。l==r时再进一次循环，那么结束时l的位置就是应该插入的位置。
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r)
        {
        	int mid = (l + r) / 2;
        	if(nums[mid] < target)	l = mid+1;
        	else	r = mid-1;
        }
        return l;
    }
};

int main()
{
	Solution s;
	vector<int> nums{ 1,3,5,6 };
	cout<<s.searchInsert(nums, 2)<<endl;
}

