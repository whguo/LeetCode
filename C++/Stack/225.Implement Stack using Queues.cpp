/*
使用队列实现堆栈。
*/
/*
思路：不需要两个队列，每次插入一个数，先入队列尾，然后根据队列的长度，
	  循环将队列头部的数依次放到末尾，相当于把队列反向。然后就变成了堆栈顺序。
 */
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
	queue<int> myqueue; 
    void push(int x) 
    {
    	myqueue.push(x);
    	for(int i=0; i < myqueue.size()-1; ++i)
    	{
    		myqueue.push(myqueue.front());
    		myqueue.pop();
    	}
    } 

    int pop() 
    {
        int x = myqueue.front();
        myqueue.pop();
        return x; 
    }

    int top() { return myqueue.front(); }  

    bool empty() { return myqueue.empty(); }
};
int main()
{
	MyStack obj;
    obj.push(1);
    cout<< obj.top() <<endl;
    obj.push(2);
    cout<< obj.pop() <<endl;
    cout<< obj.top() <<endl;
    cout<< obj.empty() <<endl;
}

