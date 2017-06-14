/*
求两个数的和，不能使用加减符号。
*/
/*
思路：a与b的和可以转换为这两个部分的和:
	1)a^b，表示如果没有进位，求和的结果。
	2)(a&b)<<1，表示所有的进位。
	一直重复计算这两个部分，直到进位为0即可。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
        int sum = a;
        while (b != 0)
        {
            sum = a ^ b;
            b = (a & b) << 1;
            a = sum;
        }    
        return sum;
    }
};
int main()
{
	Solution s;
	cout<<s.getSum(11,989)<<endl;
}

