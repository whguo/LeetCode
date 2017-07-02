/*
给出两个数组，第一个是第二个的子集，且均没有重复数字
返回第一个数组中的每一个数，在第二个数组中的下一个比它大的数，没有返回-1。
nums1 = [4,1,2], nums2 = [1,3,4,2].
返回[-1,3,-1]
 */
/*
思路：使用堆栈，对于第二个数组中的每个数压栈。
	  如果栈顶数小于当前数，那么使用map记录比栈顶数大的下一个数是当前数，然后出栈。
	  所以栈中的数一定是递减的。
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int>	mystack;
        unordered_map<int,int>	mymap;
        for(int n:nums)
        {
        	while(!mystack.empty() && mystack.top()<n)
        	{
        		mymap[mystack.top()] = n;
        		mystack.pop();
        	}
        	mystack.push(n);
        }
        vector<int>	result;
        for(int n:findNums)	result.push_back(mymap.count(n)? mymap[n]:-1);
        return result;
    }
};
int main()
{
	Solution s;
	vector<int> nums1{1,2,4};
	vector<int> nums2{2,0,3,4,1};
    vector<int> out =  s.nextGreaterElement(nums1,nums2);
    for(int n:out)
        cout<<n<<" ";
    cout<<endl;
}

