/*
长度为N的数组中包含0,1,2...n（缺失一个），找出缺失的那个数
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

    	/*全部求和，然后最差即可
        int length = nums.size();
        int sum = 0;
        for(int i=0; i < length; ++i)
        {
        	sum += nums[i];
        }
        return length*(length+1)/2-sum;*/

        //位操作
        //初始让result为n,循环第二句先后与或0,1..,n-1,结果是0到n的与或值
        //循环第一句结果是0到x-1,x+1到n的与或，合起来结果为所求x。
        int length = nums.size(),i = 0;
        int result = length;
        while(i<length)
        {
        	result ^= nums[i];
        	result ^= i;
        	++i;
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(6);
	nums.push_back(4);
	cout<<s.missingNumber(nums)<<endl;
}