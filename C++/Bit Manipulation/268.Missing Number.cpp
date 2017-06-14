/*
数组长度n，存的数是0--n中的n个数，找出缺失的那个。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size(),result = n;
		for(int i=0; i < n; ++i)
			result = result ^ nums[i] ^ i;
		return result;
    }
};
int main()
{
	Solution s;
	vector<int> nums{0,1,2,3,5,6};
	cout<<s.missingNumber(nums)<<endl;
}

