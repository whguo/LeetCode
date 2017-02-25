/*
一个右移过的有序数组，寻找最小元素。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1 , mid;
        while(left<right)
        {
        	mid = (left + right)/2;
        	if(nums[mid]>=nums[left] && nums[mid]>=nums[right])
        	{
        		left = mid+1;
        	}
        	else
        	{
        		right = mid;
        	}
        }
        return nums[left];
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	cout<<s.findMin(nums)<<endl;
}