/*
最佳购买和抛售股票的时机，，求最大收益。
购买次数不限制，但是卖掉一个股票后第二天不能买进，即有一天的冷却时间
*/
/*
思路：用两个数组buy和sell记录到当前买进和卖出最高收入。
buy[i] = max(buy[i-1],sell[i-2]-prices[i]);
sell[i] = max(sell[i-1],buy[i-1]+prices[i]);
省略数组用几个变量代替可化简为如下代码。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if(n == 0)	return 0;
        int buy = INT_MIN,presell = 0 , sell = 0;
        for(int price:prices)
        {
        	int tmp = presell;
        	presell = sell;
        	sell = max(sell,buy+price);
        	buy = max(tmp-price,buy);        	
        }
        return sell;
    }
};
int main()
{
	Solution s;
	vector<int> prices{7, 1, 5, 3, 6, 4};
	cout<<s.maxProfit(prices)<<endl;    
}

