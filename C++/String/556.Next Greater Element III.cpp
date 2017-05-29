/*
给出一个32位正整数，返回下一个比它大的，而且与它有相同数字的正整数。
如果没有，返回-1。
例如：12返回21,21返回-1。
*/
/*
思路：先把数转换为字符串，然后求出全排列中下一个数，然后转换为long long类型比较。
*/
#include <iostream>
#include <limits.h>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
	int nextGreaterElement(int n) {
		string digits = to_string(n);
        next_permutation(begin(digits), end(digits));   //求出最小的大于n的字符串
        long long res = stoll(digits);  //将字符串转换为long long类型
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};

int main()
{
	Solution s;
	cout<<s.nextGreaterElement(1254)<<endl;
}

