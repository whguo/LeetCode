/*
求数组中出现超过一半的那个数
*/
/*
思路：选举法。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
        int major = nums[0], count = 1;
        for(int i=1; i < nums.size(); ++i)
        {
        	if(major==nums[i])	++count;
        	else
        	{
        		--count;
        		if(!count)	major = nums[i],count = 1;
        	}
        }
        return major;
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,1,-3,4,1,2,1,-5,1};
	cout<<s.majorityElement(nums)<<endl;
}

