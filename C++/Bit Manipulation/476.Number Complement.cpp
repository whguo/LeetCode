/*
给出一个正整数，给出它的反码代表的整数。这个数有几位，则反几位。
比如：给出1，只有1位，反过来，是0。给出5，3位，反过来是010，返回2。
*/
/*
思路：给出的数每次右移一位，掩码从1开始每次左移一位，如果数的最后一位是0，则把结果中的数该位改成1。
 */
#include <iostream>
using namespace std;


class Solution {
public:
	int findComplement(int num) {
        int result = 0 , mask = 1;
        while(num)
        {
        	if((num & 1)==0)		result |= mask;;
        	num >>= 1;
        	mask <<= 1;
        }
        return result;
    }
};
int main()
{
	Solution s;
	cout << s.findComplement(5) <<endl;
}

