/*
计算两个数组的交集,出现多少次，返回多少次。
*/
/*
思路：1.O(n)解法，使用unordered_map。用nums1初始化一个map，记录每个数出现的次数。
然后对nums2中的每个数，如果在map中且出现次数不为0，加入result数组，该数出现的次数减1。
2.O(nlongn)解法。对nums2排序，然后对nums1中的每个数，使用二分法在nums2寻找。
找到则加入result数组。
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
	vector<int> nums1{1,2,3,2,1};
	vector<int> nums2{2,2};
	nums1 = s.intersect(nums1,nums2);
	for(int n:nums1)
		cout<<n<<" ";
	cout<<endl;
}

