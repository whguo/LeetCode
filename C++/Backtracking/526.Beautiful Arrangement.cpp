/*
如果整数1到N的排列，第i个数满足下列规则之一，则称该排列为“美丽排列”。
1.第i个位置的数字可以被i整除
2.i可以被第i个位置的数字整除
给定数字N，求有多少个美丽排列
注意：N是正整数并且不超过15
*/
/*
思路：回溯，从后往前试，后面的数大，试的次数少。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        vector<int> myvec;
        for (int i=0; i < N; ++i) myvec.push_back(i+1);
        return counts(N, myvec);
    }
    int counts(int n,vector<int>& myvec)
    {
    	if(n <= 0)	return 1;
    	int result = 0;
    	for(int i=0; i < n; ++i)
    	{
    		if(myvec[i]%n==0 || n%myvec[i]==0)
    		{
    			swap(myvec[i],myvec[n-1]);
    			result += counts(n-1,myvec);
    			swap(myvec[i],myvec[n-1]);
    		}
    	}
    	return result;
    }
};
int main()
{
	Solution s;
	cout << s.countArrangement(4);
}

