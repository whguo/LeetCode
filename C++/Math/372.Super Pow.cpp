/*
求a的b次方对1337求模运算的结果。
b是一个大数，由数组给出。
*/
/*
思路：ab % k = (a%k)(b%k)%k
a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (a^123456 % k)^10 % k * (a^7 % k) % k
令f(a, b) = a^b % k
f(a,1234567) = f(a, 1234560) * f(a, 7) % k = f(f(a, 123456),10) * f(a,7)%k;

更简单的做法是欧拉定理：若n,a为正整数,且n,a互质,则:a^φ(n) 和 1 除以 n 的余数相同。
欧拉函数：对正整数n，欧拉函数是小于n的正整数中与n互质的数的数目，也称φ函数。
1337有两个因数7和191。φ(1337)=φ(7)*φ(191)=6*190=1140。
(1)如果a有两个因数7和191，那么a%1337=0;
(2)如果a没有因数7和191，那么(a^b)%1337=(a^(b%φ(1337)))%1337=(a^(b%1140))%1337;
(3)如果a有7或者191中的一个，二者相似，假如是7。
	令a=(7^n)x , b = 1140p+q(0<q<=1140)
	那么经过推导a^b %1337 = a^q %1337。
过程见：https://discuss.leetcode.com/topic/50586/math-solusion-based-on-euler-s-theorem-power-called-only-once-c-java-1-line-python
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
	int superPow(int a, vector<int>& b) {
        if(b.size()==0)		return 1;
        int last_digit = b.back();
        b.pop_back();
        return powmod(superPow(a,b),10)*powmod(a,last_digit)%1337;
    }
    int powmod(int a,int c)
    {
    	a %= 1337;
    	int result = 1;
    	for(int i=0; i < c; ++i)
    		result = (result*a) % 1337;
    	return result;
    }
    /*欧拉定理解法
    int superPow(int a, vector<int>& b) {
    	if (a % 1337 == 0) return 0;
    	int p = 0;
    	for (int i : b) p = (p * 10 + i) % 1140;
    	if (p == 0) p += 1140;
    	return power(a, p, 1337);
	}
	int power(int x, int n, int mod) {
    	int ret = 1;
    	for (x %= mod; n; x = x * x % mod, n >>= 1) if (n & 1) ret = ret * x % mod;
    	return ret;
	}
    */
};
int main()
{
	Solution s;
	vector<int> nums{1,2};
	cout<<s.largestDivisibleSubset(2,nums)<<endl;
}

