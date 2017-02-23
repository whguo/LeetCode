/*
寻找数组中所有超过总数三分之一的数。
要求线性的时间及O(1)的空间。
*/
/*
思路：
投票选举法，第一次遍历，投出两个候选。
第二次遍历对这两个候选计数。
 */


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int length = nums.size();
        if(length==0)	return result;
        int cand1 = 0, cand2 = 0;
        int count1 = 0, count2 = 0;
        for(int i=0; i < length; ++i)
        {
        	if(cand1 == nums[i])		++count1;
        	else if(cand2 == nums[i])		++count2;
        	else if(0 == count1)
        	{
        		cand1 = nums[i];
        		count1 = 1;
        	}
        	else if(0 == count2)
        	{
        		cand2 = nums[i];
        		count2 = 1;
        	}
        	else
        		--count1,--count2;
        }
        count1=0,count2=0;
        for(int i=0; i < length; ++i)
        {
        	if(cand1==nums[i])	++count1;
        	if(cand2==nums[i])	++count2;
        }
        if(count1>(length/3))	result.push_back(cand1);
        
        //判断一下是否相等，避免加入相同的数
        if(cand1!=cand2 && count2>(length/3))	result.push_back(cand2);
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums,out;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	out = s.majorityElement(nums);
	for(int i = 0; i < out.size(); ++i)
	{
		cout<<out[i]<<endl;
	}
}