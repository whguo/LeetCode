/*
将数组中的给定元素删除，返回删除后的长度。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     int removeElement(vector<int>& nums, int val) {
        int length = nums.size(),pos = 0;
        for(int n:nums)
        {
        	if(n!=val)	nums[pos++] = n;
        }
        return pos;
    }
};

int main()
{
	Solution s;
	vector<int> nums{3,2,2,3};
	cout<<s.removeElement(nums, 3)<<endl;
}

