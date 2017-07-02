/*
给出一个UNIX类型的绝对地址，化简该地址。
*/
/*
思路：使用栈。
     需要注意的点：1)遇到..时栈为空，不能出栈。 
     2)结尾不是'/'时，为避免在循环外再写一次对tmp的判断，可以手动在path末尾加一个'/'。 
     3)遍历完毕后，栈如果为空，最后的结果是"/"。
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
        stack<string>	mystack;
        string tmp = "";
        path += '/';
        for(int i=1; i < path.length(); ++i)
        {	
        	if(path[i]=='/')
        	{
        		if(tmp.length()==1 && tmp[0]=='.')	;
        		else if(tmp.length()==2 && tmp[0]=='.' && tmp[0]=='.')
        		{
        			if(!mystack.empty()) mystack.pop();
        		}
        		else if(tmp.length()>0)
        			mystack.push(tmp);
        		tmp = "";
        		continue;
        	}
        	tmp += path[i];	
        }
        string result = "";
        while(!mystack.empty())
        {
        	result = "/"+mystack.top()+result;
        	mystack.pop();
        }
        return result.length()==0? "/":result;
    }
};

int main()
{
	Solution s;;
	cout<<s.simplifyPath("/a/./b/../../c/")<<endl;
	cout<<s.simplifyPath("/../")<<endl;
	cout<<s.simplifyPath("///")<<endl;
	cout<<s.simplifyPath("/...")<<endl;
	cout<<s.simplifyPath("/a/./b/dd/ff/c/")<<endl;
	cout<<s.simplifyPath("/.")<<endl;
}