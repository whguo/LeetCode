/*
判断一个数是不是3的乘方。
如何不使用循环做？
*/
/*
思路：
*/
#include <iostream>
using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
    	// 1162261467 is 3^19,  3^20 is bigger than int  
    	return ( n>0 &&  1162261467%n==0);

    	//return fmod(log10(n)/log10(3), 1)==0;
    }
};
int main()
{
	Solution s;
	cout << s.isPowerOfThree(81) << endl;
}

