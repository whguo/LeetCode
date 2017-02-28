/*
数组中的数满足，1<=nums[i]<=n，n是数组长度。
要求找出数组中重复出现的数
 */
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
	{
		int length = nums.size();
		vector<int> result;
        for(int i=0; i < length; ++i)
        {
        	if(nums[fabs(nums[i])-1]<0)
        		result.push_back(fabs(nums[i]));
        	else
        		nums[fabs(nums[i])-1] = -nums[fabs(nums[i])-1];
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums,disapperard;
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(7);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(1);
	disapperard=s.findDuplicates(nums);
	for(int i=0; i<disapperard.size(); ++i)
	{
		cout<<disapperard[i]<<endl;
	}
}