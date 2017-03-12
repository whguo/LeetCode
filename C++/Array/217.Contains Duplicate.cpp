/*
返回数组中是否有重复数字
*/


#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	set<int> result;
    	for(int i=0; i < nums.size(); ++i)
    	{
    		result.insert(nums[i]);
    	}
    	return nums.size()!=result.size();

    	//一行就可以，vector直接转成set。
    	//return nums.size() > set<int>(nums.begin(), nums.end()).size(); 
    }
};

int main()
{
	Solution s;
	vector<int> nums{2,1,1,4,1,2,2};
	cout<<s.containsDuplicate(nums)<<endl;
}