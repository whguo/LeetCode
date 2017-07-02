/*
使用堆栈实现队列。
*/
/*
思路：用两个栈。
 */
#include <iostream>
#include <stack>
using namespace std;

class MyStack {
public:
	stack<int> mystack1;
	stack<int> mystack2; 
    void push(int x) {
        mystack1.push(x);
    }
    
    int pop() 
    {    	
        int res = peek();
        mystack2.pop();
        return res;
    }
    
    int peek() 
    {
        if(mystack2.empty())
        {
        	while(!mystack1.empty())
        	{
        		mystack2.push(mystack1.top());
        		mystack1.pop();
        	}
        }
        return mystack2.top();
    }
    
    bool empty() {        return mystack2.empty() && mystack1.empty();    }
    
};
int main()
{
	MyStack obj;
    obj.push(1);
    cout<< obj.peek() <<endl;
    obj.push(2);
    cout<< obj.pop() <<endl;
    cout<< obj.peek() <<endl;
    cout<< obj.empty() <<endl;
}

