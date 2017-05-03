/*
求数组nums中是否存在k的整数倍，并且长度至少为2的连续子数组和。
*/
/*
思路：循环求和，每次加数组中的一个数，并且对和求K的模。
如果模的结果重复出现，那么存在连续子数组是k的整数倍。
因为要求长度至少为2，所以求和之后，模应该记录下来，下一次求和再放入set。
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size() , sum = 0, pre = 0;
        unordered_set<int>	modk;
        for(int i=0; i < n; ++i)
        {
        	sum += nums[i];
        	int mod = k==0? sum:sum%k;
        	if(modk.count(mod))	return true;
        	modk.insert(pre);
        	pre = mod;
        }
        return false;
    }
};
int main()
{
	Solution s;
	vector<int> nums{23,2,4,6,7};
	cout << s.checkSubarraySum(nums,6) << endl;
}

