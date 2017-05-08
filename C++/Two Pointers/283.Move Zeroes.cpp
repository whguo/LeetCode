/*
把数组中的0全都挪到最后。
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0,j = 0,length = nums.size();
        while(j < length)
        {
        	if(nums[j]!=0)
        	{
        		nums[i++] = nums[j];
        	}
        	++j;
        }
        while(i<length)
        {
        	nums[i++] = 0;
        }
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(1);
	s.moveZeroes(nums);
	for(int i=0; i<nums.size(); ++i)
	{
		cout<<nums[i]<<endl;
	}
}