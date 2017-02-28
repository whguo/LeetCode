/*
数组包含n+1个数，每个数都在1到n之间，假设只有一个重复的元素，找到它。
不能修改数组的值，只能用O(1)的空间，时间复杂度小于O(n^2)。
有一个重复的元素，但是它可能出现很多次。
*/
/*
思路：遇到这种限定数组中的数小于长度n的题，优先考虑的负号标记法。
但是“不允许修改数组” 与 “常数空间复杂度”这两个限制条件意味着：不能负号标记，禁止排序，并且不能使用Map等数据结构。

二分法+鸽笼原理：
二分枚举答案范围，使用鸽笼原理进行检验
根据鸽笼原理，给定n + 1个范围[1, n]的整数，其中一定存在数字出现至少两次。
假设枚举的数字为 n / 2：
遍历数组，若数组中不大于n / 2的数字个数超过n / 2，则可以确定[1, n /2]范围内一定有解，
否则可以确定解落在(n / 2, n]范围内。
小于O(n2)的运行时间复杂度可以联想到使用二分将其中的一个n化简为log n。

环检测方法O(n)：
问题的一般形式如下：给定一个函数f，序列x_i的定义为

    x_0     = k       (for some k)
    x_1     = f(x_0)
    x_2     = f(f(x_0))
    ...
    x_{n+1} = f(x_n)

假设函数f从定义域映射到它本身，此时会有3种情况。
首先，如果定义域是无穷的，则序列是无限长并且没有循环的。
例如，函数 f(n) = n + 1，在整数范围内满足这个性质 - 没有数字是重复的。
 第二，序列可能是一个闭合循环，这意味着存在一个i使得x_0 = x_i。在这个例子中，序列在一组值内无限循环。
 第三，序列有可能是的“ρ型的”。

 用快慢指针，先找到一个点，这个点一定是在环内的。
 然后再用一个指针从头开始，另一个指针在环内，相等的位置就是环的起点，即结果。

 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	/*负号标记法
        int length = nums.size();
        if(length<=1)	return -1;
        for(int i=0; i < length; ++i)
        {
        	if(nums[fabs(nums[i])-1]<0)
        	{
        		return fabs(nums[i]);
        	}
        	else
        	{
        		nums[fabs(nums[i])-1] = -nums[fabs(nums[i])-1];
        	}
        }*/
        /*二分法+鸽笼原理
    	int low = 1 , high = nums.size()-1, mid , count;
    	while(low<=high)
    	{
    		mid = (low+high)>>1;
    		count = 0;
    		for(int i=0; i < nums.size(); ++i)
    		{
    			if(nums[i]<=mid)	count++;
    		}
    		if(count>mid)	high = mid-1;
    		else low = mid+1;
    	}
    	return low;*/

    	//环检测方法
    	if (nums.size() > 1)
		{
			int slow = nums[0];
			int fast = nums[nums[0]];
			while (slow != fast)
			{
				slow = nums[slow];
				fast = nums[nums[fast]];
			}

			fast = 0;
			while (fast != slow)
			{
				fast = nums[fast];
				slow = nums[slow];
			}
			return slow;
		}
		return -1;
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	//nums.push_back(2);
	//nums.push_back(1);
	cout<<s.findDuplicate(nums);
}