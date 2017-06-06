/*
给出一个数s，在正数数组中找出一个子数组，使得子数组数字的和大于等于s
返回子数组的最短长度
*/
/*
思路：两个下标，一个头一个尾。
     开始尾向前挪累加，加到和超过s后，头往前动累减。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
        int length = nums.size(),minlen = length+1, current=0;
        for(int i = 0, j = 0; j < length; ++j)
        {
            current += nums[j];
            while(current>=s)
            {
                minlen = min(minlen,j-i+1);
                current -= nums[i++];
            }
        }
        return (minlen==length+1)? 0 : minlen;
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,7,1,2,4,3,2};
	cout<<s.minSubArrayLen(7,nums)<<endl;
}

