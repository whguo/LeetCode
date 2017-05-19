/*
字符串以Z字形摆放，按照每横行的顺序重新输出.
"PAYPALISHIRING"摆放为
P   A   H   N
A P L S I I G
Y   I   R
返回"PAHNAPLSIIGYIR"。
*/
/*
思路：第一行和最后一行的间隔为2*(numRows-1)
	中间第i行的间隔为：2*(numRows-1)-2*i和i*2交替。
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if(numRows==1)  return s;
        int gap = 2 * (numRows-1) , length = s.length();;
        string result = "";
        for(int j = 0; j < length; j += gap)
        	result += s[j];
        for(int i = 1; i < numRows-1; ++i)
        {
        	int newgap = 2*i;
        	for(int j=i; j < length; j += newgap)
        	{
        		result += s[j];
        		newgap = gap - newgap;
        	}
        }
        for(int j = numRows-1; j < length; j += gap)
        	result += s[j];
        return result;
    }
};

int main()
{
	Solution s;;
	cout<<s.convert("PAYPALISHIRING",3)<<endl;
	cout<<s.convert("ABCDEFGHIJKLMN",4)<<endl;
}

