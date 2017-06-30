/*
求n位数中，没有重复数字的数的个数。
*/
/*
思路：用排列组合的思想。
1位数，10个都是。
2位数，第一个位置可以放9个，第二个位置也是9个，共9*9
....
结果为：9*9*8*7..+.....+9*9+10
再推导一步变成：10+9*(9+9*8+9*8*7+...)
*/
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if(n==0)    return 1;
		int total = 0,tmp = 1, i = 9;
        while(--n)
        {
        	tmp *= i--;
        	total += tmp;
        }
        return 9*total + 10;
    }
};
int main()
{
	Solution s;
	cout << s.countNumbersWithUniqueDigits(4) << endl;
}

