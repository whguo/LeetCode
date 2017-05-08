/*
0,1,2分别代表红色，白色和蓝色。将数组按照红白蓝的顺序排好。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0 , right = nums.size()-1;
        for(int i=0; i <= right; ++i)
        {
        	if(nums[i]==0)	nums[left++]=0;
        	else if(nums[i]==2)
        	{
        		nums[i] = nums[right];
        		nums[right--] = 2;
        		--i;
        	}
        }
        for(int i = left; i <= right; ++i)
        {
        	nums[i] = 1;
        }
    }
};

int main()
{
	Solution s;;
	vector<int> nums{1,2,0,2,1,0,2};
	s.sortColors(nums);
	for(int i = 0; i < nums.size(); ++i)
	{
		cout<<nums[i]<<endl;
	}
}

