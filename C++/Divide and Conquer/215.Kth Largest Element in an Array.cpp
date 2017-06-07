/*
求数组中第k大的数。
*/
/*
思路：使用最大堆。Multiset和priority queue都是以最大堆为基础实现的。
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
        multiset<int>	myset;
        for(int n:nums)
        {
        	myset.insert(n);
        	if(myset.size() > k)
        		myset.erase(myset.begin());
        }
        return *myset.begin();
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,-1,-3,4,6,2,-6,-5,11};
	cout<<s.findKthLargest(nums,3)<<endl;
}

