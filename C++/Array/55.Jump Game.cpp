/*
数组元素代表从该位置向后最多走的步数，求是否能到达最后一个。
*/

#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int length = nums.size();
		if(length<=1)	return true;
        for(int i=1; i < length-1; ++i)
        {
        	if(nums[i-1]==0)	return false;
        	nums[i] = max(nums[i-1]-1,nums[i]);
        }
        return nums[length-2]>0;
    }
};

int main()
{
	Solution s;
	//vector<int> nums{ 2,3,1,1,4};
	vector<int> nums{ 3,2,1,0,4};
	cout<<s.canJump(nums)<<endl;
}

