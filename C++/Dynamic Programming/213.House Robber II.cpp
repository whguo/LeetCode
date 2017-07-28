/*
抢劫一个环形社区，相邻的房间被抢会触发警报。
*/
/*
思路：先计算第1到n-1个房子的最大，然后计算第2到n个的最大，比较两者返回最大值。
可以使用两个临时变量存储前前一个和前一个。不用使用整个数组。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if(n ==0 )	return 0;
		else if(n==1)	return nums[0];

        int pre = 0, cur = 0 , first;
        for(int i=0; i+1 < n; ++i)
        {
        	int tmp = max(cur,pre+nums[i]);
        	pre = cur;
        	cur = tmp;
        }
        first = cur, pre = 0, cur = 0;
        for(int i=1; i < n; ++i)
        {
        	int tmp = max(cur,pre+nums[i]);
        	pre = cur;
        	cur = tmp;
        }
        return max(first,cur);
    }
};
int main()
{
	Solution s;
	vector<int> nums{2,3,4,4};
	cout<<s.rob(nums)<<endl;
}

