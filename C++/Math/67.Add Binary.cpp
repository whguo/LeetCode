/*
两个字符串表示两个二进制数，求二者的和。
*/

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1,flag = 0,sum=0;
        string result="";
        while(i>=0 || j>=0 || flag)
        {
        	sum = flag;
        	if(i>=0)	sum += (a[i--]-'0');
        	if(j>=0)	sum += (b[j--]-'0');
        	flag = sum/2;
        	result = char(sum%2+'0')+result;
        }
        return result;
    }
};
int main()
{
	Solution s;
	cout<<s.addBinary("11","1")<<endl;
}

