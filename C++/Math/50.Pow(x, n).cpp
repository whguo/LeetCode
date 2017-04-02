/*
求x的n次方。
*/
/*
思路：将n次幂“折半”,即：Pow(x,n)=Pow(x,n/2)*Pow(x,n/2)
从而得到一种时间复杂度为O(logn)的方法。
注意：幂n<0时，不能简单的通过“-n”来转化成正数，因为INT_MIN直接相反数会溢出。
 */

#include <iostream>
#include <cmath>
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
	cout<< s.myPow(12, 3)<<endl;
}

