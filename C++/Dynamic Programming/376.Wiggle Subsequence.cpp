/*
摆动序列指的是序列中连续两个数的差值正负交替出现。
问给出数组中最长的子数组长度，它是摆动序列。
例如：[1,17,5,10,13,15,10,5,16,8]， 返回7，最长为[1,17,10,13,10,16,8]。
*/
/*
思路：使用两个数组up和down，一个记录上升一个记录下降。
如果当前的大于前一个，那么表示当前是上升，此时最大长度为up[i] = down[i-1]+1，down保持不变。
如果当前的小于前一个，那么表示当前是下降，此时最大长度为down[i] = up[i-1]+1，up保持不变。
如果当前的等于前一个，那么两者都不变。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)	return n;
        vector<int>	down(n),up(n);
        up[0] = 1, down[0] = 1;
        for(int i=1; i < n; ++i)
        {
        	if(nums[i] > nums[i-1])
        		up[i] = down[i-1]+1, down[i] = down[i-1];
        	else if(nums[i] < nums[i-1])
        		down[i] = up[i-1]+1, up[i] = up[i-1];
        	else
        		down[i] = down[i-1], up[i] = up[i-1];
        }
        return max(down[n-1],up[n-1]);
    }
};
int main()
{
	Solution s;
	vector<int> nums{1,17,5,10,13,15,10,5,16,8};
	cout << s.wiggleMaxLength(nums) <<endl;
}

