/*
判断数组中是否有重复。
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>	myset;
        for(int i=0; i < nums.size(); ++i)
        {
        	if(myset.count(nums[i])!=0)
        	{
        		return true;
        	}
        	myset.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,2,3,4,5,6,1};
	cout << s.containsDuplicate(nums) << endl;
}

