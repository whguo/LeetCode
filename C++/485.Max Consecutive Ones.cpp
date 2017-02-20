/*
数组中只有0和1，求出连续最长的1的个数
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int consecutive = 0, current = 0, length = nums.size();
        for(int i = 0; i < length; ++i)
        {
        	if(nums[i] ==0 )
        	{
        		consecutive = (consecutive<current) ? current:consecutive;
        		current = 0;
        	}
        	else
        	{
        		current += 1;
        	}
        }
        consecutive = (consecutive<current) ? current:consecutive;
        return consecutive;
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	cout<<s.findMaxConsecutiveOnes(nums);
}