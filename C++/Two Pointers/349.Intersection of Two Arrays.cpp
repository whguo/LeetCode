/*
求两个数组的交集，结果不能有重复数字，顺序任意。
*/
/*
思路：用unordered_set。
 */
#include <iostream>
#include <vector> 
#include <unordered_set> 
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>		result;
        unordered_set<int>	myset(nums1.begin(),nums1.end());
       	for(int n:nums2)
       	{
       		if(myset.count(n))
       		{
       			result.push_back(n);
       			myset.erase(n);
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

