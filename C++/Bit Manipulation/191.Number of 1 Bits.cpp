/*
返回32位无符号数中二进制位为1的个数
*/
/*
思路：n&n-1可以把n的最后一个是1的二进制位设置为0。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
        int count = 0;
        while(n)
        {
        	n = n & (n-1);
        	++count;
        }
        return count;
    }
};

int main()
{
	Solution s;	
	cout << s.hammingWeight(43261596) <<endl;
}

