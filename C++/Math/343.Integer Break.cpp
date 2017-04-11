/*
给出整数n，把n分为至少两个数的和，让这几个数乘积最大。
返回最大乘积。n大于等于2，小于等于58。
*/
/*
思路：5以上的数都符合一个规律：要让乘积最大，需要尽量多的3。
那么，当n对3取余，为0时，显然这些3相乘，为1时，少一个3，多有一个4，
为2时，多乘个2。
数学推导：把n分为x份，乘积为x的n/x次方，求导，导数为0时的点为e，
靠近e的点只能是2和3。大的数都是3，小的数如4，分成2*2乘积最大。
*/
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	int integerBreak(int n) {   
        if(n<4)    return n-1;
        if(n==4)    return 4;
        int m = n%3, r = n/3;
        if(m==0)    return pow(3,r);
        if(m==1)    return pow(3,r-1)*4;
        return pow(3,r)*2;
    }
};
int main()
{
	Solution s;
	cout << s.integerBreak(50) << endl;
}

