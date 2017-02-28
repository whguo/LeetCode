/*
找出数组中第三大的数，如果不存在，返回最大的数。
相同的数算一个，如[1,1,2]，返回2，第三大的不存在
 */
/*
注意：
初始化要用长整型long的最小值，否则当数组中有INT_MIN存在时，程序就不知道该返回INT_MIN还是最大值first了
如：[1,2,INT_MIN]无法判断返回2还是INT_MIN
 */
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums)
	{
		long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for (int num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second && num < first) {
                third = second;
                second = num;
            } else if (num > third && num < second) {
                third = num;
            }
        }
        return (third == LONG_MIN || third == second) ? first : third;
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(7);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(1);
	cout<<s.thirdMax(nums);
}