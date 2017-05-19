/*
给出字符串，找出最长子串，不含重复字母。
思路：用map记录下每个字母最近出现的位置。
用start记录当前子串的开始，如果遍历到字母最近出现位置大于start，start。
每次循环更新最大长度。
*/

#include <iostream>
#include <cstring>
#include <windows.h>
#include <windef.h>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> mymap(256, -1);
		int maxLen = 0, start = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (mymap[s[i]] > start)
                start = mymap[s[i]];
            mymap[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
	}

};

int main()
{
	Solution s;
	string str = "aab";
	cout << s.lengthOfLongestSubstring(str) << endl;
}

