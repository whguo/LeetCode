/*
解码字符串。编码规则为：数字[字符串]，表示字符串出现了多少次。
例如：
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
/*
思路：1.使用两个栈，一个存放字符串，一个存放重复次数int型。
	    碰到数，循环得到连续数字，然后压入int型栈。
	    碰到左括号，压入一个空字符串。
	    碰到字母，字符串栈顶出栈，加上字母，然后再压栈。
	    碰到右括号，字符串栈顶出栈，重复次数出栈，重复加上字符串，得到重复结果。
	        然后字符串栈顶再出栈，加上重复结果，再压回栈中。
	    2.使用递归方法。碰到数字就递归括号中的内容，然后重复加上。
 */
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helpdecodeString(s,i);
    }

    string helpdecodeString(const string& s,int& i)
    {
    	string result = "";
    	while(i < s.length() && s[i] != ']')
    	{
    		if(!isdigit(s[i]))	result += s[i++];
    		else
    		{
    			int n = 0;
    			while(i < s.length() && isdigit(s[i]))
    				n = n*10 + s[i++] - '0';
    			++i;  //跳过'['
    			string tmp = helpdecodeString(s,i);
    			++i;  //跳过']'
    			while(n-- > 0)	result += tmp;
    		}
    	}
    	return result;
    }
};
int main()
{
	Solution s;
	cout<< s.decodeString("2[abc]3[cd2[g]]ef");
}

