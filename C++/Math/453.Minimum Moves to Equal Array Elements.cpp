/*
给一个数组，对数组的每一次操作是让其中的n-1个数加1，剩余1个保持不变。
问最少多少次操作可以让所有的数都一样大。
*/
/*
思路：n-1个数加1，相当于剩余1个数减1。那么要让所有数都相同，都减到等于最小数即可。
所以最少次数为sum(array)-n*min。
 */
#include <iostream>
#include <cmath>
#include <windows.h>
#include <windef.h>
using namespace std;

class Solution {
public:
	int minMoves(vector<int>& nums) {
        int minnum = nums[0] , sum = 0 , length = nums.size();
        for(int n:nums)
        {
        	sum += n;
        	minnum = min(minnum,n);
        }
        return sum-length*minnum;

    }
};
int main()
{
	Solution s;
	vector<int> nums{1,2,3};
	cout << s.minMoves(nums) << endl;
}

