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
	nums.push_back(2);
	nums.push_back(2);
	cout<<s.containsDuplicate(nums)<<endl;
}