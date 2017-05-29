/*
判断一个字符串是否重复的子串构成。
*/
/*
思路：递归做法，最后一个测试用例递归太深内存溢出。
	暴力求法，找与第一个字母相同的位置，然后循环判断每一个部分是否相同，直至末尾。速度太慢。
	
	要考虑到字符串的特点，如果是可以重复的，那么子串长一定是总长的因数。
	此外，只需要考虑一半即可，如果一半没找到，那么一定不是。
	于是有如下解法：只针对总长度的因数i判断，将字符串循环左移i位，如果与原字符串相同，则返回true。
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool repeatedSubstringPattern(string str) {
        string nextStr = str;
        int len = str.length();
        if(len < 1) return false;
        for(int i = 1; i <= len / 2; i++){
            if(len % i == 0){
                nextStr = leftShift(str, i);
                if(nextStr == str) return true;
            }
        }
        return false;
    }
    
    string leftShift(string &str, int l){
        string ret = str.substr(l);
        ret += str.substr(0, l);
        return ret;
    }

	/*暴力解法
	bool repeatedSubstringPattern(string s) {
		int length = s.length();
        if(length < 2)	return false;
        for(int i=1; i < length; ++i)
        {
        	if(s[i]==s[0])
        	{
        		for(int j=i; j < length; j+=i)
        		{
        			for(int k=0; k < i; ++k)
        			{
        				if(j+k>=length || s[k]!=s[j+k])	break;
        				if(j+k==length-1 && k==i-1)	return true;
        			}
        		}
        	}
        }
        return false;
	}*/

	/*递归做法
	bool repeatedSubstringPattern(string s) {
        int length = s.length();
        if(length < 2)	return false;
        for(int i=1; i < length; ++i)
        {
        	if(s[i]==s[0] && repeatedSubstring(s.substr(0,i),s.substr(i)))
        	{
        		return true;
        	}
        }
        return false;
    }
    bool repeatedSubstring(string p,string s)
    {
    	if(s.length()==0)	return true;
    	else if(p.length()>s.length())	return false;
    	for(int i=0; i < p.length(); ++i)
    	{
    		if(p[i]!=s[i])	return false;
    	}
    	return repeatedSubstring(p,s.substr(p.length()));
    }*/
};

int main()
{
	Solution s;
	cout<<s.repeatedSubstringPattern("abab")<<endl;
}

