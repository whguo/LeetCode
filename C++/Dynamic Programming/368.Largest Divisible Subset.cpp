/*
给定一个数组，求其中的一个最大子集，要求该子集中任意的两个元素满足 x % y ==0 或者 y % x==0
给出[1,2,4,8,10]，返回[1,2,4,8]。
*/
/*
思路：若a<b且b%a==0 , b<c 且 c%b==0那么必然有c%a==0。然后动态规划。
不能只考虑后边的大的数，前面的也要考虑。
如：[4,8,10,240]，结果出现[10,240]的情况（到240只考虑了10，没考虑8）
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size() , maxlength = 0, maxindex = 0;
        sort(nums.begin(),nums.end());
        vector<int> dp(n),parents(n);
        for(int i=n-1; i >= 0; --i)
        {
        	for(int j=i; j < n; ++j)
        	{
        		if(nums[j]%nums[i]==0 && dp[i]<dp[j]+1)
        		{
        			dp[i] = dp[j]+1;
        			parents[i] = j;
        			if(dp[i]>maxlength)	maxlength = dp[i], maxindex = i;
        		}
        	}
        }
        vector<int>	result;
        for(int i=0; i < maxlength; ++i)
        {
        	result.push_back(nums[maxindex]);
        	maxindex = parents[maxindex];
        }
        return result;
    }
};
int main()
{
	Solution s;
	vector<int> nums{1,2,4,8,10};
	vector<int> out = s.largestDivisibleSubset(nums);
	for(int n:out)
		cout<<n<<endl;    
}

