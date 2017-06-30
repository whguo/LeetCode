/*
寻找n个数的全排列中第k大的数。
*/
/*
思路：1.利用求全排列的方法，递归找到第k个。
	  2.使用数学的方法。挨个寻找应该放在s[i]位置的数字。
	    n个数中，每个数开头的数有(n-1)!个，用k除以(n-1)!就能找到第一个数是什么。
	    然后k对(n-1)!求模，得到剩余的没排的数。以此类推。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
    	string s(n,'0');
    	int factorial = 1, index;
    	for(int i=0,j=1; i < n; ++i,++j)
    	{
    		//阶乘，也就是一共有多少种排列
    		factorial = factorial*j;
    		s[i] = j+'0';
    	}
    	--k;	//转换为从0开始计数
    	for(int i=0; i < n; ++i)
    	{
    		factorial /= n-i;
    		index = k/factorial + i;    //应该放在s[i]位置的下标
    		char ch = s[index];

    		//把index前面的都向后挪一个
    		while(index > i)
    		{
    			s[index] = s[index-1]; --index;
    		}
    		s[i] = ch;          //s[i]放置正确的数字
    		k %= factorial;     //k剩下没排的部分    		
    	}
    	return s;
    }
};
int main()
{
	Solution s;
    cout << s.getPermutation(4,10) <<endl;
}

