/*
给出数组和目标数，找出数组中有多少对数的绝对距离是目标数。
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		int result=0;
		if(k!=0)
		{
        	set<int> myset;
        	for(int i=0; i < nums.size(); ++i)
        	{
        		myset.insert(nums[i]);
        	}
        	for(set<int>::iterator it=myset.begin(); it != myset.end(); ++it)
        	{
        		if(myset.find(*it+k)!=myset.end()) ++result;
        	}
        }
        else
        {
        	map<int,int> mymap;
        	map<int,int>::iterator it;
        	for(int i=0; i < nums.size(); ++i)
        	{
        		it = mymap.find(nums[i]);
        		if(it==mymap.end())
        		{
        			mymap.insert({nums[i],0});
        		}
        		else
        		{
        			if(it->second==0)
        			{
        				++result;
        				it->second = 1;
        			}
        		}
        	}
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,3,1,5,4,1};
	cout<<s.findPairs(nums,0)<<endl;
}

