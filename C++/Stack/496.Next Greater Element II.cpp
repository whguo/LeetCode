/*
给出一个循环数组(最后一个元素的下一个元素是第一个)，找出每个数下一个比它大数，没有的话-1。
例如：[1,2,1]，返回 [2,-1,2]
最后一个1，需要循环寻找。
 */
/*
思路：使用堆栈保存下标。
	  因为大于某个数的数可能都在它的前面，需要循环才能找到，
	  所以考虑循环数组两次，相当于把数组在后面复制了一次，长度2n，这样大于某个数的数
	  就在它的后面(或者没有)。
	  第一次循环数组，对每个数的下标压栈。
	  如果栈顶指向的数小于当前数，那么栈顶下标对应的数的结果就是当前数。
	  同样，栈中下标对应的数一定是递减的。
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    	int n = nums.size(),n2;
        stack<int>	mystack;
        vector<int>	result(n,-1);
        for(int i=0,n2 = n*2; i < n2; ++i)
        {
        	int num = nums[i%n];
        	while(!mystack.empty() && nums[mystack.top()]<num)
        	{
        		result[mystack.top()] = num;
        		mystack.pop();
        	}
        	if(i < n)	mystack.push(i);
        }        
        return result;
    }
};
int main()
{
	Solution s;
	vector<int> nums{1,2,1};
	vector<int> out =  s.nextGreaterElements(nums);
	for(int n:out)
		cout<<n<<" ";
	cout<<endl;
}

