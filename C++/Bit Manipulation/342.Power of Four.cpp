/*
判断一个数是不是4的次方。
*/
/*
思路：首先判断是不是2的次方。然后判断二进制位1是不是在奇数位置上。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
		return num > 0 && (num&(num-1))==0 && (num&0x55555555)!=0;
    }
};
int main()
{
	Solution s;
	cout<<s.isPowerOfFour(256)<<endl;
}

