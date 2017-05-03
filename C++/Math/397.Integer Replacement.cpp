/*
给一个正整数n，如果是偶数，用n/2代替n，如果是奇数，用n+1或者n-1代替n。
直到n变为1。求最少次数。
*/
/*
思路：递归，每次循环右移直到最后一位是1。
 */
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
	int integerReplacement(int n) {
		if (n == 2)	return 1;
		if (n == 4)	return 2;
		int i = 0;
		if (n == 2147483647)	--n;// 防止越界
		while (n && ((n & 1)==0))
		{
			n = n >> 1;
			++i;
		}
		if (n == 1)	return i;
		return i + 1 + min(integerReplacement(n - 1), integerReplacement(n + 1));
	}
};
int main()
{
	Solution s;
	cout << s.integerReplacement(2147483647) << endl;
}

