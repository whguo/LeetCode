/*
给出一个32位无符号整型数，把它按二进制位翻转。
*/
/*
思路：1.一个从头，一个从尾，将两个二进制位互换。
	  2.m每次与n&1进行或运算之后向左移。一位一位构造出32位的数。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		/*思路1
        int i = 16;
        uint32_t left = 0x80000000,right = 0x00000001;
        while(i-- > 0)
        {
        	uint32_t tmp1 = n & left, tmp2 = n & right;
        	if(tmp1)	n = n | right;
        	else n = n & (~right);
        	if(tmp2)	n = n | left;
        	else n = n & (~left);
        	left >>= 1;
        	right <<= 1;
        }
        return n;*/

        uint32_t m = 0;
    	for (int i = 0; i < 32; ++i, n >>= 1) 
    	{
        	m <<= 1;
        	m |= n & 1;
    	}
    	return m;
    }
};

int main()
{
	Solution s;	
	cout << s.reverseBits(43261596) <<endl;
}

