/*
有序数组，分段返回数字字符串
*/


#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    	int length = nums.size();
		vector<string> result;
		if (length == 0)	return result;
		string temp = "";		
		int start = nums[0];
		for (int i = 0; i < length - 1; ++i)
		{
			if (nums[i] + 1 != nums[i + 1])
			{
				temp = to_string(start);
				temp += (nums[i] == start) ? "" : "->" + to_string(nums[i]);
				result.push_back(temp);
				start = nums[i + 1];
			}
		}
		if (nums[nums.size() - 1] - start == 0)
			result.push_back(to_string(start));
		else
		{
			result.push_back(to_string(start) + "->" + to_string(nums[length - 1]));
		}
		return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	vector<string> out;
	nums.push_back(-1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(8);
	out = s.summaryRanges(nums);
	for(int i=0; i < out.size(); ++i)
	{
		cout<<out[i]<<","<<endl;
	}
}