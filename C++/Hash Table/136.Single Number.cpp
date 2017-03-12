/*
数组中除了一个数其他每个数出现两次，找到该数。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int n:nums)
        {
        	result ^= n;
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,2,3,3,2,10,11,15,10,11,1};
	cout<<s.singleNumber(nums)<<endl;
}

