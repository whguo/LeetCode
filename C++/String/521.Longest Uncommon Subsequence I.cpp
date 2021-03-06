/*
给定两个字符串，计算其“最长不公共子序列”。
最长不公共子序列是指：两字符串中某一个的子序列，该子序列不是另一个字符串的子序列，并且长度最长。
子序列是指从一个序列中删除一些字符，剩余字符顺序保持不变得到的新序列。
任何字符串都是其本身的子序列，空串不属于任意字符串的子序列。
返回最长不公共子序列，若不存在，返回-1。
注意：1.两字符串长度均不超过100。 2.输入字符串只包含小写字母a-z。
*/
/*
思路：若两字符串不相等，选择较长的字符串返回长度即可。
	否则返回-1。（若两字符串相等，则任意字符串的子串均为另一个的子串）
 */
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Solution {
public:
	int findLUSlength(string a, string b) {
		return (a == b )? -1:max(a.length(),b.length());
    }
};

int main()
{
	Solution s;
	cout<<s.findLUSlength("aba","cbc")<<endl;
}

