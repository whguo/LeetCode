/*
最佳的购买和抛售股票的时机，最多买卖各一次，求最大收益。
*/
/*
思路：记录前面最小值，和最大落差。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size()==0)    return 0;
        int maxpro = 0 , curmin = prices[0];
        for(int i=1; i < prices.size(); ++i)
        {
        	maxpro = max(maxpro,prices[i]-curmin);
        	curmin = min(curmin,prices[i]);
        }
        return maxpro;
    }
};
int main()
{
	Solution s;
	vector<int> prices{7, 1, 5, 3, 6, 4};
	cout<<s.maxProfit(prices)<<endl;
}

