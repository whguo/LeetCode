/*
给出一个非空字符串和一个字典，字典包含一系列非空字符串。
问该字符串是否可以分割成一个或这几个字典中的小字符串。
例如：s = "leetcode",dict = ["leet", "code"]， 返回true
*/
/*
思路：dp加递归。首先从字典里找一个匹配s的开头部分的，然后递归s剩余的部分。
这个长度寻找完毕后，让其dp值为0，表示该长度的字符串在字典中没有匹配，以后就可以跳过了。
 */
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
	vector<int>	dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty())	return true;
        if(dp.empty())	dp.resize(s.size()+1,-1);
        for(int i=0; i < wordDict.size(); ++i)
        {
        	int l = wordDict[i].size();
        	if(l > s.size())	continue;
        	if(s.substr(0,l) == wordDict[i])
        	{
        		if(dp[l]==-1)  //如果没计算过，那么计算一下
        		{
        			bool tmp = wordBreak(s.substr(l),wordDict);
        			if(tmp)	return true;
        			dp[l] = 0; //表示后边长度为l的字符串计算过了，但是是false。
        		}
        	}
        }
        return false;
    }
};
int main()
{
	Solution s;
	vector<string> wordDict{"my","name","is","gwh"};
	cout<<s.wordBreak("myis",wordDict)<<endl;
}

