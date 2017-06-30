/*
给出字符串，返回它的一系列分割，每个分割中的子字符串都是回文的。
*/
/*
思路：DFS递归。每次判断从start开始的字符串是否是回文的，是的话加入临时vector，然后递归。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
	vector<vector<string>> result;
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        helpPartition(s,0,tmp);
        return result;
    }
    void helpPartition(const string& s,int start,vector<string>& tmp)
    {
    	if(start==s.length())
    	{
    		result.push_back(tmp);
    		return;
    	}
    	for(int i=start; i < s.length(); ++i)
    	{
    		if(isPalindrome(s,start,i))
    		{
    			tmp.push_back(s.substr(start,i-start+1));
    			helpPartition(s,i+1,tmp);
    			tmp.pop_back();
    		}
    	}
    }
    bool isPalindrome(const string& s,int start,int end)
    {
    	while(start < end)
    		if(s[start++] !=s[end--])	return false;
    	return true;
    }
};
int main()
{
	Solution s;
	vector<vector<string>> out = s.partition("acddcab");
	for(auto vec:out)
	{
		for(string s:vec)
			cout<<s<<" ";
		cout<<endl;
	}
}

