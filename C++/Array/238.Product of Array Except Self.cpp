/*
长度为n(n>1)的数组nums，返回一个数组output，使得
output[i]为数组中除了nums[i]其余数的乘积。不能使用除法。
*/
/*
思路：
#执行两趟循环：
#第一趟正向遍历数组，计算x0 ~ xi-1的乘积
#第二趟反向遍历数组，计算xi+1 ~ xn-1的乘积
 */


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> right(length),left(length);
        right[0] = 1 , left[length-1] = 1;
        for(int i = 1; i < length; ++i)
        {
        	right[i] = right[i-1]*nums[i-1];
        }
        for(int i = length-2; i >= 0; --i)
        {
        	left[i] = left[i+1]*nums[i+1];
        }
        for(int i = 0; i < length; ++i)
        {
        	left[i] *= right[i];
        }
        return left;
    }
};

int main()
{
	Solution s;
	vector<int> nums,out;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(4);
	//nums.push_back(6);
	//nums.push_back(4);
	out = s.productExceptSelf(nums);
	for(int i = 0; i < out.size(); ++i)
	{
		cout<<out[i]<<endl;
	}
}