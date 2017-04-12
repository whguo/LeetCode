/*
把string转换成一个整型数。
*/
/*
思路：考虑四种情况：
1.去除最开始的空白符
2.数的符号
3.越界问题
4.不标准的输入。
 */

#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int sign = 1, result = 0, i = 0;
		while(str[i]==' ') ++i;//前面的空白符
		if(str[i]=='-' || str[i]=='+')//符号
		{
			sign = 1 - 2*(str[i++] == '-'); 
		}
		while(str[i] >= '0' && str[i]<='9')//不标准输入
		{
			if(result > INT_MAX/10 || (result == INT_MAX/10 && str[i]-'0'>7)) //越界
			{
				if(sign==1)	return INT_MAX;
				else	return INT_MIN;
			}
			result = 10*result + (str[i++]-'0');
		}
		return result*sign;
    }
};
int main()
{
	Solution s;
 	cout<<s.myAtoi("-123");
}

