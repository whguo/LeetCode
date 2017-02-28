/*
寻找数组中一个数，该数占了数组一半以上。
*/
/*
思路：
O(N)的解决方法，从头开始计数，相同加一，不同减一，减到0换数字。
 */


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int length = nums.size();
        if (length==0)  return 0;
        int num,count = 0;
        for(int i=0; i < nums.size(); ++i)
        {
            if(count==0)
            {
                num = nums[i];
                count = 1;
            }
            else if(nums[i]==num)   ++count;
            else    --count;
        }
        return num;
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(1);
	cout<<s.majorityElement(nums);
}