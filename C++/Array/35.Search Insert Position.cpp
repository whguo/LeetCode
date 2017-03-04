/*
一个有序数组，一个目标值。
如果数在数组中，返回数组中的下标。
如果不在，返回它应该插入的位置。
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0; i < nums.size(); ++i)
        {
        	if(target<=nums[i])	return i;
        }
        return nums.size();
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,3,5,6};
	cout<<s.searchInsert(nums, 2)<<endl;
}

