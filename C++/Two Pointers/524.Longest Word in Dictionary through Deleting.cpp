/*
一个字符串字典和一个字符串，找出字典中的一个最长字符串，
使得给定的字符串删掉一些字母可以变成该字符串（顺序不变）。
*/
#include <iostream>
#include <cstring>
#include <windows.h>
#include <windef.h>
#include <vector>
using namespace std;

class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
        int maxindex = -1, maxlen = 0, slength = s.size();
        for(int i=0; i < d.size(); ++i)
        {
        	int k = 0, dilength = d[i].size();

        	//用两个指针判断当前字符串是否匹配
        	for(int j=0; j<slength && slength-j >= dilength-k ; ++j)
        	{
        		if(d[i][k]==s[j])	++k;
        	}
        	//如果匹配
        	if(k==dilength)
        	{
        		if(maxlen<dilength) maxlen = dilength, maxindex = i;
        		else if(maxlen==dilength)
        		{
        			//如果长度一样，判断字典顺序大小，记下顺序小的
        			if(d[maxindex].compare(d[i])>0)	maxindex = i;
        		}
        	}
        }
        return maxindex==-1? "" : d[maxindex];
    }
};

int main()
{
	Solution s;;
	vector<string> dic{"ale","apple","monkey","aplea"};
	cout<<s.findLongestWord("abpcplea",dic)<<endl;
}

