/*
返回数组的两个下标，两个数和为给定数。
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
     vector<int> twoSum(vector<int>& nums, int target) {

     	/*O(N*N)的方法
        int length = nums.size();
        for(int i=0; i < length-1; ++i)
        {
        	for(int j=i+1; j < length; ++j)
        	{
        		if(nums[i]+nums[j]==target)	return vector<int> {i,j};
        	}
        }*/

        //O(n)方法，用map。
        map<int,int> mymap;
        for(int i=0; i < nums.size(); ++i)
        {
        	map<int,int>::iterator it = mymap.find(target-nums[i]);
        	if(it==mymap.end())
        		mymap.insert({nums[i],i});
        	else
        		return vector<int> {it->second,i};
        }
    }
};

int main()
{
	Solution s;
	vector<int> nums{2, 7, 11, 15};
	nums = s.twoSum(nums, 17);
	cout<<nums[0]<<" "<<nums[1]<<endl;
}

