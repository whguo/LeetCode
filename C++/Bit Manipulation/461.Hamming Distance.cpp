/*
计算两个数的二进制距离，也就是二进制位不同的个数。
*/
/*
思路：先求与或，然后计算与或结果中有多少个二进制位是1。
 */
#include <iostream>
using namespace std;


class Solution {
public:
	int hammingDistance(int x, int y) {
        int count = 0 , n = x ^ y;
        while(n)
        {
            n = n&(n-1);
            ++count;
        }
        return count;
    }
};
int main()
{
	Solution s;
	cout << s.hammingDistance(5,7) <<endl;
}

