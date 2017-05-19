/*
给出一组大中小括号，判断它们是否成对。
*/
/*
思路：用堆栈。
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> mystack;
        for(char ch:s)
        {
        	switch(ch)
        	{
        		case '{':
        		case '[':
        		case '(': mystack.push(ch);break;
        		case "}": if(!mystack.empty() && mystack.top()=='{') mystack.pop();else return false; break;
        		case "]": if(!mystack.empty() && mystack.top()=='[') mystack.pop();else return false; break;
        		case ")": if(!mystack.empty() && mystack.top()=='(') mystack.pop();else return false; break;
        		default:	;
        	}
        }
        return mystack.empty();
    }
};

int main()
{
	Solution s;;
	cout<<s.isValid("[]{})")<<endl;
}

