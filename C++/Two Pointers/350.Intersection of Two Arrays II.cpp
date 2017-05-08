/*
求两个数组的交集，有重复数字结果中要体现出来，顺序任意。
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
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>		result;
        unordered_map<int,int>	mymap;
        for(int n:nums1)
        	++mymap[n];
       	for(int n:nums2)
       	{
       		if(mymap.count(n)!=0 && mymap[n]!=0)
       		{
       			result.push_back(n);
       			--mymap[n];
       		}
       	}
       	return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums1{1,1,1,2,2,3},nums2{1,1,1,2,2,3,4};
	nums1 = s.intersect(nums1,nums2);
	for (int i = 0; i < nums1.size(); ++i)
	{
		cout<<nums1[i]<<endl;
	}
}

