/*
给定一个数组，求其中的一个最大子集，要求该子集中任意的两个元素满足 x % y ==0 或者 y % x==0
给出[1,2,4,8,10]，返回[1,2,4,8]。
*/
/*
思路：若a<b且b%a==0 ,  b <c 且 c%b==0那么必然有c%a==0。然后动态规划。
不能只考虑后边的大的数，前面的也要考虑。
如：[4,8,10,240]，结果出现10,240的情况（到240只考虑了10，没考虑8）
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int length = nums.size(),maxlength = 0,maxindex=0;
		sort(nums.begin(), nums.end());
        vector<int>	dp(length,0);
        vector<int>	parent(length,0);

        //逆向寻找，方便定位结果的下标
        
        for(int i=length-1; i >=0 ; --i)
        {
        	for(int j=i; j < length; ++j)
        	{
        		if(nums[j]%nums[i]==0 && dp[i]<1+dp[j])
        		{
                    //dp[i]<1+dp[j]非常重要
        			//通过把nums[i]放入dp[j]中，dp[j]可以形成一个更大的子集
        			dp[i] = dp[j] + 1;
        			parent[i] = j;
        			if(dp[i]>maxlength)
        				maxlength = dp[i],maxindex = i;
        		}
        	}
        }
        vector<int> result;
        for(int i=0; i < maxlength; ++i)
        {
        	result.push_back(nums[maxindex]);
        	maxindex = parent[maxindex];
        }
        return result;
    }
};
int main()
{
	Solution s;
	vector<int> nums{1,2,3,4,8,10,12};
	nums = s.largestDivisibleSubset(nums);
	for(auto n:nums)
		cout<<n<<endl;
}

