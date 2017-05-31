/*
实现次方运算pow(x,n)。
*/
/*
思路：快速幂。
注意，一定要有n==2的部分，因为不断在调用2次方。
n<0时，不能直接1除以n的绝对值次方，因为次方比较大时，会除以0。
改为1/x的次方即可。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
        if(n<0) return 1/x * myPow(1/x, -(n+1));
        if(n==0) return 1;
        if(n==2) return x*x;
        if(n%2==0) return myPow( myPow(x, n/2), 2);
        else return x*myPow( myPow(x, n/2), 2);
    }
};

int main()
{
	Solution s;
	cout<<s.myPow(2, 14)<<endl;
}

