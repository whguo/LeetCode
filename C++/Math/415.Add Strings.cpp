/*
对两个字符串代表的数字求和。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
        int flag = 0, sum = 0;
        int m = num1.size()-1,n = num2.size()-1;
        string result = "";
        while(m>=0 || n>=0)
        {
        	sum = flag;
        	if(m>=0)	sum += num1[m--]-'0';
        	if(n>=0)	sum += num2[n--]-'0';
        	result = char(sum%10+'0') + result;
        	flag = sum / 10;
        }
        if(flag)	result = "1"+result;
        return result;
    }
};
int main()
{
	Solution s;
	cout << s.addStrings("2345","9999") << endl;
}

