/*
给定字符串str和整数k，翻转str的前k个字符，每2k个字符翻转k个。
如果总长小于k，那么全部翻转。如果总长大于等于k，小于2k，翻转前k个，后边的不变。
*/
/*
思路：先求出一共有多少个k，然后偶数个k位置进行翻转。
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
        int length = s.length(), count = length/k;
        for(int i=0; i <= count; ++i)
        {
        	if((i & 0x01) == 0)
        	{
        		int end = i*k+k-1;
        		if(end>=length)	end = length-1;
        		for(int start=i*k; start < end; ++start,--end)
        		{
        			char tmp = s[start];
        			s[start] = s[end];
        			s[end] = tmp;
        		}
        	}
        }
        return s;
    }
};

int main()
{
	Solution s;
	cout<<s.reverseStr("abcdefgh",3)<<endl;
	cout<<s.reverseStr("abcdefghij",3)<<endl;
}

