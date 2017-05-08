/*
判断一个字符串是不是回文的。
只考虑字母和数字，忽略空格，标点等其他字符。
*/
#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
        for(int i = 0, j = s.size()-1;i < j; ++i,--j)
        {
        	while(i<j && !isalnum(s[i]))	++i;
        	while(i<j && !isalnum(s[j]))	--j;
        	if(toupper(s[i])!=toupper(s[j]))	return false;	
        }
        return true;
    }
};

int main()
{
	Solution s;;
	cout<<s.isPalindrome("A man, a plan, a canal: Panama")<<endl;
	cout<<s.isPalindrome("ab")<<endl;
}

