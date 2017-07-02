/*
给出逆波兰表达式，计算结果值。
*/
/*
思路：如果是数字，进栈。如果是计算符，出栈两次，计算结果，然后压栈。
      判断是否是数字可以判断字符串的最后一个字符的ASCII码是否在0-9之间。
      不能使用第一个是因为会有负数。
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>	mystack;
        int x,y;
        for(auto s:tokens)
        {
        	//注意这个判断不能用s[0]，因为可能有负数。
        	if(s.back()<'0' || s.back()>'9')
        	{
        		x = mystack.top();
        		mystack.pop();
        		y = mystack.top();
        		mystack.pop();
        		switch(s[0])
        		{
        			case '+':	y = x+y;	break;
        			case '-':	y = y-x;	break;
        			case '*':	y = x*y;	break;
        			case '/':	y = y/x;	break;
        		}
        		mystack.push(y);
        	}
        	else
        		mystack.push(stoi(s));
        }
        return mystack.top();
    }
};
int main()
{
	Solution s;
	vector<string> tokens{"4", "13", "5", "/", "+"};
	cout << s.evalRPN(tokens) <<endl;
}

