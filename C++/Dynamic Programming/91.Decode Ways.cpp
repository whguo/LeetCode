/*
1-26分别对应A-Z，求出数字串可以对应的所有字母串的个数。
例如：12可以代表"AB"，也可以代表"L"，返回2。
*/
/*
思路：dp[n]代表下标为n之前的数字对应的字母串个数。因为s的下标为0到n-1，所以结果返回dp[n]。
递推公式为：dp[n] = (s[i-1]不为0)*dp[i-1]+(s[i]-1和s[i-2]组合可以解出一个字母)*dp[i-2]
因为除0以外的其他数字均可以单独解，所以s[i-1]不为0的时候，dp[i]需要加上dp[i-1]，意思是
前i-2个有多少种解的方法，第i-1个字母单独解的情况就有多少种。
如果s[i]-1和s[i-2]组合可以解出一个字母，
前i-3个有多少种解的方法，第i-2个和第i-1个组合解的情况就有多少种。
那么dp[n]表示的前i-1个数字的解的个数，就是第i-1个单独解的情况加上第i-2和第i-1组合解的情况。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
    	int n = s.size();
    	if(n==0 || s[0]=='0')	return 0;	//如果长度为0或者第一个字符是0，那么无法解码
    	int dp0 = 1, dp1 = 1, dp2;
    	for(int i=2; i <= n; ++i)
    	{
    		dp2 = (int)(s[i-1] != '0')*dp1 + (int)((s[i-2])=='1' || (s[i-2]=='2' && s[i-1]<'7'))*dp0;
    		dp0 = dp1;
    		dp1 = dp2;
    	}
    	return dp1;
    }
};
int main()
{
	Solution s;
	cout<<s.numDecodings("123")<<endl;
}

