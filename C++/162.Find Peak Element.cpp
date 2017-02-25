/*
找到数组中的一个峰值元素，就是比邻居两个元素都大的元素，返回其下标。
假设nums[-1]=nums[n]=-无穷
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int length = nums.size();
        for(int i=1; i < length; ++i)
        {
        	if(nums[i]<nums[i-1])	return i-1;
        }
        return length-1;
    }
};

int main()
{
	Solution s;
	vector<int> nums,out;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	//nums.push_back(5);
	//nums.push_back(6);
	//nums.push_back(7);
	cout<<s.findPeakElement(nums)<<endl;
}