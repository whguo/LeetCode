/*
整数序列1,2,3,4,5,6,7,8,9,10,11, ...
返回第n个数字。如：输入11，返回0。n小于2^31。
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findNthDigit(int n) {

		//base 和 nums都会越界，所以用long
        long base = 9 , num = 1;
		int i = 1;
		while (n - base*i > 0)
		{
			n -= base * i++;
			base *= 10;
			num *=10;
		}
		num += (n - 1) / i; //得出是哪个数
		i = i - (n - 1) % i - 1;//计算需要除以几个10，以得到该位
		while (i>0)
		{
			num /= 10;
			--i;
		}
		return num % 10;
    }
};
int main()
{
	Solution s;
	cout << s.findNthDigit(2885) << endl;
}

