/*
有重复数的排序数组，找出某数开始和结束的下标位置。
时间复杂度为O(log(n))。
*/
/*
思路：使用两次二分法。
1.首先寻找左边界。初始化l=0,r=n-1。
If(A[mid]<target)，那么数都在mid的右边，令l=mid+1。
If(A[mid]>target)，那么数开始的位置在mid左侧，令r=mid-1。
If(A[mid]=target)，那么数开始的位置在mid左侧或者就是mid，令r=mid。
在后两种情况下，都是把往同一方向移动，可以合并为r=mid。
在循环l<r结束后，l和r要么都指向该数的左边界，要么该数不存在。判断一下即可。
2.然后寻找右边界。与1中类似。
If(A[mid]>target)，令r=mid-1。
If(A[mid]<=target)，令l=mid。
但是此时循环终止时有些问题，如果剩余[5,7]，target=5，l已经等于mid，将进入死循环。
用一个小技巧，计算mid时，令mid=(l+r)/2+1。
由于1中是r在向左移，则mid=(l+r)/2时，r和mid不会相等，因为是向下取整。
但是2中是l向右移，mid=(l+r)/2时，l会和mid相等，所以让其向上取整，则不会进入死循环。
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        if(nums.size()==0) return result;
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
        	int mid = (l + r) / 2;
        	if(nums[mid] < target)	l = mid+1;
        	else	r = mid;
        }
        if(nums[l] != target)	return result;
        else	result[0] = l;

        r = nums.size()-1;
        while(l < r)
        {
        	int mid = (l + r) / 2 + 1;
        	if(nums[mid] > target)	r = mid - 1;
        	else l = mid;
        }
        result[1] = r;
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums{ 5, 7, 7, 8, 8, 10 };
	nums = s.searchRange(nums, 8);
	for(int n:nums)
		cout<<n<<" ";
	cout<<endl;
}

