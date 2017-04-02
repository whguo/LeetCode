/*
求两个数的商，不能用乘除法和去模，只要整数部分。
*/
/*
思路：每次循环除数向左移一位，直到除数大于被除数。
然后再对被除数中剩余数和原除数做相同处理。
例如：18除以3,dividend=18,divisor=3. 3左移1位6，左移2位12，左移3位24，大于18.
此时记住左移两位，也就是4，18此时表示为18=3*4+2*4。从18中减掉12，剩6，
再做刚才的操作，得到左移1位即可，也就是2，最后结果4+2=6。
两种溢出情况：
1.除数为0
2.被除数是INT_MIN,除数是-1.
 */
#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if(!divisor || dividend==INT_MIN && divisor==-1)
			return INT_MAX;
		int sign = (divisor<0 ^ dividend<0)? -1 : 1;
		long long dvd = labs(dividend);
		long long dvs = labs(divisor);
		int result = 0;
		while(dvd >= dvs)
		{
			long long temp = dvs, multiple = 1;
			while(dvd >= (temp<<1))
			{
				temp <<= 1;
				multiple <<= 1;
			}
			dvd -= temp;
			result += multiple;
		}
		return sign==1? result : -result;
    }
};
int main()
{
	Solution s;
 	cout<<s.divide(-100,15);
}

