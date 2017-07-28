/*
给出一个大于等于正整数，把它分成至少两个正整数的和，返回分成这些数的最大乘积。
*/
/*
思路：5以上的数都符合一个规律：要让乘积最大，需要尽量多的3。
那么，当n对3取余，为0时，显然这些3相乘，为1时，少一个3，多有一个4，为2时，多乘个2。
数学推导：把n分为x份，乘积为x的n/x次方，求导，导数为0时的点为e，
靠近e的点只能是2和3。大的数都是3，小的数如4，分成2*2乘积最大。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int integerBreak(int n) {
        if(n <4)	return n-1;
        else if(n == 4) 	return 4;

        int a = n/3 , b = n%3;
        if(b == 0)	return pow(3,a);
        else if(b == 1)	return pow(3,a-1)*4;
        else return pow(3,a)*2;
    }
};
int main()
{
	Solution s;
	cout<<s.integerBreak(18)<<endl;    
}

