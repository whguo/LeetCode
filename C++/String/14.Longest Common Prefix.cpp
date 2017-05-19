/*
寻找给出的所有string的最长共同前缀子串。
*/
/*
思路：对第一个字符串的每一个字母循环找即可。
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
        int strlength = strs.size();
        if(strlength==0)	return "";
        string result = "";
        for(int i=0; i < strs[0].length（）; ++i)
        {
        	int ch = strs[0][i];	
        	for(int j=1; j < strlength; ++j)
        	{
        		if(i>=strs[j].length() || strs[j][i]!=ch)
        			return result;
        	}
        	result += ch;
        }
        return result;
    }
};

int main()
{
	Solution s;;
	vector<string> strs{"abc","abced","abde"};
	cout<<s.longestCommonPrefix(strs)<<endl;
}

