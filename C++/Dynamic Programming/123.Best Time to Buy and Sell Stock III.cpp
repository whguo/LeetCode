/*
最佳的购买和抛售股票的时机，最多买卖各两次，求最大收益。
买另一个之前必须卖掉上一个，而且同一天不能进行两次交易。
*/
/*
思路：循环里从下往上看，分别是买第一个，卖第一个，买第二个，卖第二个后的收益。
从下往上是为了不让下面的更改影响上面。
 */
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int hold1 = INT_MIN, hold2 = INT_MIN;
    	int release1 = 0, release2 = 0;
    	for(int price:prices)
    	{
    		release2 = max(release2, hold2+price);
    		hold2 = max(hold2, release1-price);
    		release1 = max(release1, hold1+price);
    		hold1 = max(hold1, -price);
    	}
    	return release2;
    }
};
int main()
{
	Solution s;
	vector<int> prices{7, 1, 5, 3, 6, 4};
	cout<<s.maxProfit(prices)<<endl;
}

