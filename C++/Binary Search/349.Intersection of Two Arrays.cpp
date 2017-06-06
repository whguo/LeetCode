/*
计算两个数组的交集。
*/
/*
思路：1.O(n)解法，使用unordered_set。用Nums1初始化一个set。
然后对nums2中的每个数，如果在set中，加入result数组，并把set中的该数删掉。
2.O(nlongn)解法。对nums2排序，然后对nums1中的每个数，使用二分法在nums2寻找。
找到则加入一个set中，最后把set中的数移动到一个vector中。
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
	vector<int> nums1{1,2,3,2,1};
	vector<int> nums2{2,2};
	nums1 = s.intersection(nums1,nums2);
	for(int n:nums1)
		cout<<n<<" ";
	cout<<endl;
}

