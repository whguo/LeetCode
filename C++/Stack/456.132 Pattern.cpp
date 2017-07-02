/*
给出数组，求是否有三个数ai, aj, ak，满足i < j < k and ai < ak < aj。
*/
/*
思路：使用堆栈，然后从后向前遍历，每个数都压栈。
	  如果当前数大于堆栈顶，那么说明找到一组aj和ak，记录下ak的值。
	  如果当前数小于ak，那么说明找到一组ai和ak，而且加上上面的aj和ak的关系，返回true。
 */
#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	int ak = INT_MIN;
    	stack<int>	mystack;
    	for(int i=nums.size()-1; i >= 0; --i)
    	{
    		if(nums[i] < ak)	return true;
    		else while(!mystack.empty() && nums[i]>mystack.top())
    		{
    			ak = mystack.top();
    			mystack.pop();
    		}
    		mystack.push(nums[i]);
    	}
    	return false;
    }
};
int main()
{
	Solution s;
	vector<int> nums{1,2,3,4,0};
	cout<< s.find132pattern(nums)<<endl;
}

