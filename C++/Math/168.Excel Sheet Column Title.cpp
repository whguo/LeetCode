/*
整数转换成字符串。
	1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
        if(n<=0)	return "";
        string result = "";
        while(n)
        {
        	result = char(--n%26+'A')+result;
        	n /= 26;
        }
        return result;
    }
};
int main()
{
	Solution s;
	cout<<s.convertToTitle(180)<<endl;
}

