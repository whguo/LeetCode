#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

bool solve(int m, int n, int* num)
{
	if (n < 1)	return false;
	int **dp;
	dp = (int **)malloc((n+1)*sizeof(int*));
	for (int i = 0; i <= n; ++i)
	{
		dp[i] = (int *)malloc(m*sizeof(int));
		memset(dp[i],0,m);
	}
	dp[0][0] = 0, dp[0][num[0] % m] = 1;
	for (int i = 1; i <= n; ++i)
	{
		dp[i][num[i]%m] = 1;
		for (int j = 0; j < m; ++j)
		{
			if (dp[i - 1][j] == 1)
			{
				dp[i][j] = 1;
				dp[i][(j + (num[i] % m)) % m] = 1;
			}
		}
	}
	return dp[n][0];
}

int main(){
	int m, n, i = 0;
	int *num;
	scanf("%d%d", &n, &m);
	num = (int *)malloc(n*(sizeof(int)));
	while (i < n)
	{
		scanf("%d", num + i);
		++i;
	}
	bool s = solve(m, n, num);
	if (s)
		printf("Yes");
	else
		printf("No");
	return 0;
}