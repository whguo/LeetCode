/*
判断一个数是不是2的乘方。
*/
/*
思路：return !(n&(n-1));
n和n-1的按位与是否得0。
 */
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
        while(!(n & 1))
        	n = n >> 1;
        return (n>>1) == 0;
    }
};
int main()
{
	Solution s;
	cout<<s.isPowerOfTwo(130)<<endl;
}

