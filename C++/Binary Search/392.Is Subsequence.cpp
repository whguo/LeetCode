/*
判断一个字符串是否是另一个的子串(字母顺序不能变)。
*/
/*
思路：1.转换成char*，遇到相同的字母就向下递归。
2.由于不存在回溯过程(不匹配然后向上返回)，不需要使用递归，直接循环就可以。
3.没必要使用二分法。
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
	/*递归做法
	bool isSubsequence(string s, string t) {
        char* ss = new char[s.size()+1];
        char* tt = new char[t.size()+1];
        strcpy(ss,s.c_str());
        strcpy(tt,t.c_str());
        return isSubsequence(ss,tt);
    }
    bool isSubsequence(char *s,char* t)
    {
    	if(s[0]=='\0')	return true;
    	if(t[0]=='\0')	return false;
    	for(char *p=t; *p != '\0'; ++p)
    	{
    		if(*p == *s && isSubsequence(s+1,p+1))
    			return true;
    	}
    	return false;
    }*/

    //循环做法
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0,tsize = t.size();
        while(j != tsize)
        {
        	i += (s[i]==t[j++]);
        }
        return i==s.size();
    }
};

int main()
{
	Solution s;
	cout<<s.isSubsequence("axc","ahbgdc")<<endl;
}

