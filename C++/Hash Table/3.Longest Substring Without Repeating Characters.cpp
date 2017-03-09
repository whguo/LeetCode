/*
给出字符串，找出最长子串，不含重复字母。
*/

#include <iostream>
#include <cstring>
#include <unordered_map>
#include <windows.h>
#include <windef.h>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int length = s.length();
		if (length == 0)	return 0;
		unordered_map<char, int> mymap;
		int maxlength = 1, start = 0;
		for (int i = 0; i < length; ++i)
		{
			if (mymap.find(s[i]) == mymap.end())
			{
				mymap.insert({ s[i], i });	
			}
			else
			{
				maxlength = max(maxlength,i-start);

				//注意这个位置，不能让start++,"pwwkew"这个例子错误。
				//也不能等于mymap[s[i]]+1，"abba"这个例子错误。
				start = max(start,mymap[s[i]]+1);

				mymap[s[i]] = i;
			}
		}
		return (mymap.size() == length) ? length : max(maxlength,length-start);
	}

};

int main()
{
	Solution s;
	string str = "aab";
	cout << s.lengthOfLongestSubstring(str) << endl;
}

