/*
求给定正整数的平方根，精确到整数部分。
*/
/*
思路：牛顿迭代法：初值可以任意选择。
假设方程f(x)=0在x0附近有一个根，那么用以下迭代式子：
Xn+1 = Xn - f(Xn)/f'(Xn)。 
依次计算x1,x2,x3...，那么序列将无限逼近方程的根。
此题f(x) = x^2-a，f'(x) = 2x
牛顿迭代式为Xn+1 = 1/2*(Xn + a/Xn)。
 */
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		double y0 = 0, y1 = 1; 
		while(int(y1) != int(y0))
		{
			y0 = y1;
			y1 = 1.0/2.0*(y0 + x/y0);
		} 
		return int(y1);    
    }
};
int main()
{
	Solution s;
	cout<<s.mySqrt(9)<<endl;
}

