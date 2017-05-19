/*
找出字符串中的最长回文子串
*/
/*
思路：每次循环针对一个字母，循环内先跳过与该字母相邻的相同字母。
然后分别向两边扩展。更新最大长度和初始位置。
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int length = s.length();
        if (length==0 || length==1) return s;
		int min_start = 0, max_len = 1;
		for (int i = 0; i < s.size();) {
			//剪枝，如果剩余检测长度已经小于当前最大，那么可以退出
			if (length - i <= max_len / 2) break;		
			int j = i, k = i;
			//连续相等的字母一定是回文的，所以跳过这部分
			while (k < length - 1 && s[k + 1] == s[k]) ++k;
			i = k + 1;
			while (k < length - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; }
			int new_len = k - j + 1;
			if (new_len > max_len) { min_start = j; max_len = new_len; }
		}
		return s.substr(min_start, max_len);
    }
};

int main()
{
	Solution s;;
	cout<<s.longestPalindrome("baced")<<endl;
}

