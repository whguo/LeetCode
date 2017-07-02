/*
设计一个栈，能够支持压栈，弹栈，栈顶，以及常数时间返回栈内最小数的操作。
*/
/*
思路：1.使用两个栈，一个辅助存储当前最小值。
	  2.将1简化，只有在入栈元素小于当前最小，辅助栈才入栈，不是每入栈一个元素，辅助栈都入栈。
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinStack {
public:
	/* 方法1
	vector<int>	mystack;
	vector<int>  helpminstack;
    MinStack() {        }  
    
    void push(int x) {
        mystack.push_back(x);
        if(helpminstack.size()==0)
        	helpminstack.push_back(x);
        else
        {
        	if(helpminstack.back()>x)
        		helpminstack.push_back(x);
        	else
        		helpminstack.push_back(helpminstack.back());
        }
    }    
    void pop() {
        if(mystack.size()!=0)
        {
        	mystack.pop_back();
        	helpminstack.pop_back();
        }
    }   
    int top() {    return mystack.back();    }    
    int getMin() {    return helpminstack.back();  }*/

    //方法2
    stack<int> s1;
    stack<int> s2;
    void push(int x)
    {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() 
    {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {    return s1.top();    }
    int getMin() {    return s2.top();    }
};
int main()
{
	MinStack obj;
    obj.push(4);
    obj.push(1);
    obj.push(3);
    cout<<obj.top()<<endl;
    cout<<obj.getMin()<<endl;
    obj.pop();    
    cout<<obj.top()<<endl;
    cout<<obj.getMin()<<endl;
    obj.pop();
    cout<<obj.top()<<endl;
    cout<<obj.getMin()<<endl;
}

