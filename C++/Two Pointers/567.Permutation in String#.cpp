/*
给出两个字符串，判断字符串1的某种排列是否是字符串2的一个子串。
*/
/*
思路：在s2中找到一个子字符串[i,j]包含s1中所有字母。
通过向前移动i减小子字符串长度，如果还能包含所有s1中的字母，直到子字符串长度等于s1长度，返回true。
如果子字符串中不再包含所有字母了，那么向前移动j。
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
        vector<int> count(128);
        for(int i = 0; i < s1.length(); i++) count[s1[i]]--;
        for(int l = 0, r = 0; r < s2.length(); r++) {
            if (++count[s2[r]] > 0)
                while(--count[s2[l++]] != 0) { /* do nothing */}
            else if ((r - l + 1) == s1.length()) return true;
        }
        return s1.length() == 0;
    }
};

int main()
{
	Solution s;;
	cout<<s.checkInclusion("ab","eidbaooo")<<endl;
}

