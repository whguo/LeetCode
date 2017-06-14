/*
给出两个数m和n，0 <= m <= n <= 2147483647。
求出从m到n所有数按位与的结果。
*/
/*
思路：1.从m到n每个数都做与运算，初始值为0x4fffffff
	  2.使用mask从左边开始找到第一个二进制位是1的位置，如果两个数该位置不都是1，那么返回0.
	  如果都是1，那么递归右边的数。结果为右边数计算的结果与当前mask的或运算。
	  3.实际上求的m和n二进制位相同的公共左侧。所以只要二者每次右移一位直到相同为止。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		/*方法2
        if (m <= 0 || n <= 0)	return 0;
		int mask = 0x40000000;
		while (mask && (mask & n) == 0 && (mask & m) == 0)
			mask >>= 1;
		if ((mask & n)== 0 ^ (mask & m) == 0)	return 0;
		int opmask = ~mask;
		return mask | rangeBitwiseAnd(m & opmask, n& opmask); */

		/*方法3
		int mask = 0x7fffffff;
		while((m&mask) != (n&mask))
			mask <<= 1;
		return m & mask;*/
		short count = 0;
      	while(m != n)
            m>>=1, n>>=1,++count;
      	return m << count;
    }
};

int main()
{
	Solution s;	
	cout << s.rangeBitwiseAnd(5,7) <<endl;
}

