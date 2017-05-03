/*
摆硬币：给n个硬币，第一行摆1个，第2行摆2个。。。
求摆满的行数。
*/
/*
思路：1+2+3+...+x = n
-> (1+x)x/2 = n
-> x^2+x = 2n
-> x^2+x+1/4 = 2n +1/4
-> (x+1/2)^2 = 2n +1/4
-> (x+0.5) = sqrt(2n+0.25)
-> x = -0.5 + sqrt(2n+0.25)
用求根公式会慢一些，因为8*n会越界，改用double计数会慢。
 */
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	int arrangeCoins(int n) {
		return -0.5+sqrt((double)2*n+0.25);
    }
};
int main()
{
	Solution s;
	cout << s.arrangeCoins(1804289383) << endl;
}

