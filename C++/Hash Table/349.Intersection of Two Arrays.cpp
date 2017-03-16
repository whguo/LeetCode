/*
求两个数组的交集，结果不能有重复数字，顺序任意。
*/
/*
思路：用map计数存储一个数组然后另一个对应着找。
 */
#include <iostream>
#include <vector> 
#include <unordered_map> 
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>		result;
        unordered_map<int,int>	mymap;
        for(int n:nums1)
        	++mymap[n];
       	for(int n:nums2)
       	{
       		if(mymap.count(n)!=0 && mymap[n]!=0)
       		{
       			result.push_back(n);
       			mymap[n] = 0;
       		}
       	}
       	return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums1{1,1,1,2,2,3},nums2{2,3,4};
	nums1 = s.intersection(nums1,nums2);
	for (int i = 0; i < nums1.size(); ++i)
	{
		cout<<nums1[i]<<endl;
	}
}

