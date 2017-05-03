/*
给一个数组，对数组的每一次操作是让1个数加1，或者减1。
问最少多少次操作可以让所有的数都一样大。
*/
/*
思路：假设数组已排好序，设最后相同的数为k，从数组开始寻找k。
如果k增加1，那么小于等于k的元素需要多操作一次，大于k的元素少操作一次。
那么，如果大于k的元素比小于等于k的元素多，那么我们应该增加k来减少操作次数。
所以，k应该为数组的中位数。
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int minMoves2(vector<int>& nums) {
        int n = nums.size();
        auto it = nums.begin() + n/2;

        //nth_element(first, nth, last);
        //该函数的作用是，对给定范围[first,last)内的元素进行重新布置。
        //方法是,nth位置的元素放置的值就是把所有元素排序后在nth位置的值。
        //把所有不大于nth的值放到nth的前面,把所有不小于nth的值放到nth后面.
        nth_element(nums.begin(), it, nums.end());
        int median = *it;
        int total = 0;
        for (int i : nums)
            total += abs(i-median);
        return total;
    }
};
int main()
{
	Solution s;
	vector<int> nums{1,0,0,8,6};
	cout << s.minMoves2(nums) << endl;
}

