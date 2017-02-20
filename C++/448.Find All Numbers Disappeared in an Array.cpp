/*
数组中的数满足，1<=nums[i]<=n，n是数组长度。
找出从1--n中没在数组中出现的数，要求不使用额外空间（除返回的数组外），且时间O(m)
 */
/*
思路：既要给出现的数做标记，又要保存好数字大小。所以考虑取相反数。
 */
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
	{
		int length = nums.size();
        for(int i=0; i < length; ++i)
        {
        	if (nums[fabs(nums[i])-1]>0)
        	nums[fabs(nums[i])-1] = -nums[fabs(nums[i])-1];
        }
        vector<int> result;
        for(int i=0; i < length; ++i)
        {
        	if(nums[i]>0)
        	{
        		result.push_back(i+1);
        	}
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
	nums.push_back(8);
	nums.push_back(2);
	nums.push_back(1);
	disapperard=s.findDisappearedNumbers(nums);
	for(int i=0; i<disapperard.size(); ++i)
	{
		cout<<disapperard[i]<<endl;
	}
}