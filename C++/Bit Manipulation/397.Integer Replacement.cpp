/*
给一个正整数n，如果是偶数，用n/2代替n，如果是奇数，用n+1或者n-1代替n。
直到n变为1。求最少次数。
*/
/*
思路：显然，当n为偶数时，向右移即可。
      为奇数时，需要比较n+1与n-1中哪一个二进制位是1的个数少。哪个个数少用哪个。
      但是，每次都计算二进制位中1的个数有些麻烦。
      考虑二进制后两位，如果是01，那么n-1中的1个数少。如果是11，那么n+1中的1个数小于等于n-1中的。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int integerReplacement(int n) {
        if(n==2147483647)   return 32; //越界
        int count = 0;
        while (n != 1) 
        {
        	if ((n & 1) == 0)	n = n >> 1;
        	else if (n == 3 || ((n >> 1) & 1) == 0) --n;
        	else ++n;
        	++count;
    	}
    	return count;
    }
};
int main()
{
	Solution s;
	cout<<s.integerReplacement(14)<<endl;
}

