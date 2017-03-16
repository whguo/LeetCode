/*
用给出字符串中字符任意排列，返回能得到的最长回文子串的长度。
*/

#include <iostream>
#include <vector> 
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
    	unordered_map<char,int>	mymap;
    	int count = 0;
        for(char ch:s)
        {
        	++mymap[ch];
        	if(mymap[ch]%2==0)	count += 2;
        }
        return (s.length()==count)? count:count+1;
    }
};
int main()
{
	Solution s;
	cout<<s.longestPalindrome("abccccdd")<<endl;
}

