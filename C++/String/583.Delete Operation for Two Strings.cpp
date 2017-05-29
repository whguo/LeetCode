/*
给出两个单词，找出一个单词变成另一个的最少步骤数。
每一个步骤可以删除一个字母或者添加一个字母。
*/
/*
思路：要想使二者相同，只需找出最长相同子串，其他字母去掉即可。
使用动态规划：dp[i][j]代表字符串A[i:]和B[j:]的答案。
当i==len(A)或者j==len(B)，那么其中一个字符串为空，dp[i][j]就是另一个字符串的剩余长度
当A[i]==B[j]时，dp[i][j] = dp[i+1][j+1]。
当A[i]!=B[j]时，或者删除A[i]或者删除B[j]，所以dp[i][j] = 1 + min(dp[i+1][j],dp[i][j+1])
因为是先求出i,j比较大的位置，所以是逆向的dp。
*/
#include <iostream>
#include <limits.h>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.length(), n = word2.length();
		if(m==0)	return n;
		if(n==0)	return m;
        vector<vector<int>>		dp(m,vector<int> (n));
        for(int i=0; i < m; ++i)
        	dp[i][n-1] = m - i;
        for(int j=0; j < m; ++j)
        	dp[m-1][j] = n - j;
        for(int i=m-2; i >= 0; --i)
        {
        	for(int j=n-2; j >=0; --j)
        	{
        		if(word1[i]==word2[j])
        			dp[i][j] = dp[i+1][j+1];
        		else
        			dp[i][j] = 1 + min(dp[i][j+1],dp[i+1][j]);
        	}
        }
        return dp[0][0];
    }
};

int main()
{
	Solution s;
	cout<<s.minDistance("sea","eat")<<endl;
}

