/*
有序数组,将其中的重复数字删掉，让所有数字只出现一次。
返回删除后的数组大小。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int length = nums.size();
		if(length==0)	return 0;
		int j = 0;
        for(int i=1; i < length; ++i)
        {
        	if(nums[i]!=nums[j])	nums[++j] = nums[i];
        }
        return j+1;
    }
};

int main()
{
	Solution s;;
	vector<int> nums{ 1, 3 , 3 , 5 , 5 ,8 , 8 ,9};
	cout<<s.removeDuplicates(nums)<<endl;
}

