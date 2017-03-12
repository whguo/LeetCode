/*
判断数字中是否存在两个下标i和j，有nums[i]==nums[j]
而且|i-j|<=k
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        for(int i=0; i < nums.size(); ++i)
        {
        	if(mymap.count(nums[i])==0)
        	{	
        		mymap[nums[i]]=i;
        	}
        	else
        	{
        		if(fabs(i-mymap[nums[i]])<=k)	return true;
        		mymap[nums[i]] = i;
        	}
        }
        return false;
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,0,1,1,5,6,1};
	cout << s.containsNearbyDuplicate(nums) << endl;
}

