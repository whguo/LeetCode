/*
找到数组中的一个峰值元素，就是比邻居两个元素都大的元素，返回其下标（有多个可以返回任意一个）。
假设nums[-1]=nums[n]=-无穷
*/
/*
思路：二分法搜索。因为两边都是负无穷，所以峰值一定存在。
如果nums[mid]<nums[mid+1]，那么右边一半一定有峰值，令left=mid+1;。
否则nums[mid]>nums[mid+1]，左边一半一定有峰值，且峰值有可能为mid，令right=mid。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        
        while(left < right)
        {
            int mid = (left+right)/2;
            if(nums[mid] < nums[mid+1])
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,2,3,1};
	cout<<s.findPeakElement(nums)<<endl;
}

