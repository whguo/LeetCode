/*
给出数组，求出它的所有真子集。
*/
/*
思路：位操作。如果有n个数，那么从2^n-1到0，对每个数求每一位是否为1，是1则加入子集。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		int n = nums.size(), total = 1 << n;
        while(--total >= 0)
        {
        	vector<int>	tmp;
        	for(int i=0,bit=1; i < n; ++i,bit<<=1)
        	{
        		if(total & bit)	tmp.push_back(nums[i]);
        	}
        	result.push_back(tmp);
        }
        return result;
    }
};

int main()
{
	Solution s;	
	vector<int> nums{1,2,3};
	vector<vector<int>> out = s.subsets(nums);
	for(auto vec:out)
	{
		for(int n:vec)
			cout<<n<<" ";
		cout<<endl;
	}
}

