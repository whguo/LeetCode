/*
求两个复数的乘积，结果表示为a+bi形式。
*/
/*
将数从string中提取出来，使用stringstream非常有效。
 */
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
	string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char buff;
        stringstream aa(a), bb(b), ans;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
        return ans.str();
    }
};
int main()
{
	Solution s;
	cout << s.complexNumberMultiply("1+1i","1+1i") << endl;
}

