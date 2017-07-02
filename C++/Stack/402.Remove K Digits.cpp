/*
给出字符串数，头部没有0。从中去掉k个数字，返回可以得到的最小数。
*/
/*
思路：先考虑去掉一个数字以后的最小数是什么。是去掉第一个峰值数字后的数。
	  所以去掉k个数字就是去掉k个峰值数即可。
	  由于直接去掉会导致多次从字符串中间删除内容，所以考虑使用栈。
	  循环每个字符，如果栈顶元素大于当前元素，出栈。
 */
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int digits = num.length()-k;
        string stack(num.length(),0);
        int top = -1;
        for(int i=0; i < num.length(); ++i)
        {
        	while(k>0 && top>-1 && stack[top]>num[i])
        		--top,--k;
        	stack[++top] = num[i];
        }
        //不能直接使用find_first_not_of('0')，因为如果是删除字符串长度个数字，那么index超过digits。
        //而且，如果就一个0字符，会超出范围。
        //int index = stack.find_first_not_of('0');
        int index = 0;
        while(index<digits && stack[index]=='0') ++index;
        return index==digits? "0":stack.substr(index,digits-index);
    }
};
int main()
{
	Solution s;
	cout<< s.removeKdigits("10200",1)<<endl;
	cout<< s.removeKdigits("1432219",3)<<endl;
	cout<< s.removeKdigits("10",2)<<endl;
}

