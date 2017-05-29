#include <stdio.h>
using namespace std;

#define MOD 100003

long long qpow(int m, int n)
{
	/*long long base = m%MOD, res = 1;
	for (int i = 0; i < n; ++i)
	{
		res = (res*base) % MOD;
	}*/
	long long base = m%MOD;
	long long res = 1;
	while (n)
	{
		if (n & 0x01)
			res = (res*base)%MOD;
		base = (base*base) % MOD;
		n >>= 1;
	}
	printf("%d\n", res);
	return res;
}

int solve(int m, int n) {
	long long mn = qpow(m, n);
	long long m1n1 = qpow(m - 1, n - 1);
	long long res = mn - ((m%MOD)*m1n1)%MOD;
	return (res >= 0) ? res : res + MOD;
}


int main(){
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d\n", solve(m, n));
	return 0;
}