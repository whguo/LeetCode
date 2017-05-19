/*
返回字符串中最后一个词的长度。不存在的话，返回0。
字符串只包含大小写字母和空格。
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int lastlen = 0,i;
		for(i=s.length()-1; i>=0 && s[i]==' '; --i);
        for(; i >= 0; --i)
        {
        	if(s[i]==' ')	break;
        	++lastlen;
        }
        return lastlen;
    }
};

int main()
{
	Solution s;;
	cout<<s.lengthOfLastWord("a ")<<endl;
}

