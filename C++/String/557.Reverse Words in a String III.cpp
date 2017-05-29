/*
把字符串中的每个单词翻转。相邻单词都被空格分开。
*/
/*
思路：记录单词的开始，找到空格或者到字符串末尾后，将这部分翻转。
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
        for(int start=0,blank=0; blank <= s.length(); ++blank)
        {
            //一个小技巧 ，循环加到length而不是length-1，这样可以把到末尾和碰到空格统一为一类
        	if(blank==s.length() || s[blank]==' ') // 把 blank==s.length()写前面
        	{
        		int end = blank-1;
        		while(start < end)
        		{
        			char tmp = s[start];
        			s[start++] = s[end],s[end--] = tmp;
        		}
        		start = blank + 1;
        	}
        }
        return s;
    }
};

int main()
{
	Solution s;
	cout<<s.reverseWords("Let's take LeetCode contest")<<endl;
}

