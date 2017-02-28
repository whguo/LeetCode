/*
有序数组,将其中的某些重复次数超过两次以上数字删掉一些，让这些数字只出现两次。
最后保证所有数字出现两次及以下，返回删除后的数组大小。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int length = nums.size();
		if(length<=2)	return length;
		int j = 1;
        for(int i=2; i < length; ++i)
        {
        	if(nums[i]>nums[j-1])	nums[++j] = nums[i];
        }
        return j+1;
    }
};

int main()
{
	Solution s;;
	vector<int> nums{ 1, 3 , 3 , 3 , 3 , 5 , 5 ,8 , 8 ,9 , 9};
	cout<<s.removeDuplicates(nums)<<endl;
}

