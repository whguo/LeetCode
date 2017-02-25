/*
最佳的购买和抛售股票的时机，不限购买次数，求最大收益。
*/
/*
思路：找连续增加的数列即可。
 */

#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int length = prices.size();
        if(length==0)	return 0;
        int maxpro = 0;
        for(int i=0 ; i < length-1; ++i)
        {
        	int start = i;
        	while(i <length-1 && prices[i]<prices[i+1])	++i;
        	maxpro += prices[i]-prices[start];
        }
        return maxpro;
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(8);
	//nums.push_back(2);
	cout<<s.maxProfit(nums)<<endl;
}