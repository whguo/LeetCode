/*
将数组向右挪k个位置。
*/
/*
思路：颠倒前n-k个数，颠倒后k个数，整个数组颠倒。C++实现较麻烦，没有现成的。
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	int temp,n=nums.size();
        k = k%n;  
        for(int i=0,j=n-k-1; i < j; ++i,--j)
        {
        	temp = nums[i];
        	nums[i] = nums[j];
        	nums[j] = temp;
        }
        for(int i=n-k,j=n-1; i < j; ++i,--j)
        {
        	temp = nums[i];
        	nums[i] = nums[j];
        	nums[j] = temp;
        }
        for(int i=0,j=n-1; i < j; ++i,--j)
        {
        	temp = nums[i];
        	nums[i] = nums[j];
        	nums[j] = temp;
        }

    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	s.rotate(nums,3);
	for(int i = 0; i < nums.size(); ++i)
	{
		cout<<nums[i]<<endl;
	}
}