/*
合并两个有序数组到第一个中，假设第一个数组有足够空间。
*/
/*
思路：为避免更多的挪动，从后向前赋值。
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1 , j = n-1, k = m+n-1;
        while(k>=0)
        {
        	nums1[k--] = (j<0)?nums1[i--]:(i<0)?nums2[j--]:(nums1[i]>nums2[j])?nums1[i--]:nums2[j--];
        }
    }
};

int main()
{
	Solution s;
	vector<int> nums1{1,2,5,9,11 ,0,0,0,0,0};
	vector<int> nums2{1,1,3,8,20 };
	s.merge(nums1,5,nums2,5);
	for (int i = 0; i < nums1.size(); ++i)
	{
		cout << nums1[i]<<endl;
	}
}

