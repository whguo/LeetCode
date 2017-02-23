/*
判断数字中是否存在两个下标i和j，有nums[i]==nums[j]
而且|i-j|<=k
*/


#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mymap;
        map<int,int>::iterator it;
        for(int i=0; i < nums.size(); ++i)
        {
        	it = mymap.find(nums[i]);
        	
        	if(it==mymap.end())
        	{	
        		mymap.emplace(nums[i],i);
        	}
        	else
        	{
        		if(fabs(i-it->second)<=k)	return true;
        		it->second = i;
        	}
        }
        return false;
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);
	//nums.push_back(1);
	//nums.push_back(2);
	//nums.push_back(2);
	cout<<s.containsNearbyDuplicate(nums,1)<<endl;
}