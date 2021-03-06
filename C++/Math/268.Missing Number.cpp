/*
数组长度n，存的数是0--n中的n个数，找出缺失的那个。
*/
#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {

		//位操作
		int length = nums.size(),result = length;
		for(int i=0; i < length; ++i)
			result = result ^ nums[i] ^ i;
		return result;

		/*求和方法
        int x = 0 , n = nums.size();
        for(int num:nums)
        	x += num;
        return n*(n+1)/2-x;*/
    }
};
int main()
{
	Solution s;
	vector<int> nums{0,1,2,3,5,6};
	cout<<s.missingNumber(nums)<<endl;
}

