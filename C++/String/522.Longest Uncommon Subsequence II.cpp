/*
给定一组字符串，计算其“最长不公共子序列”。
一组字符串的最长不公共子序列是指：长度最长的一个字符的子序列，该子序列不是剩余所有字符串的子序列
。子序列是指从一个序列中删除一些字符，剩余字符顺序保持不变得到的新序列。
任何字符串都是其本身的子序列，空串不属于任意字符串的子序列。
返回最长不公共子序列，若不存在，返回-1。
注意：1.两字符串长度均不超过10。 2.字符串个数2-50。
*/
/*
思路：先统计每个字符串出现的次数，然后根据字符串长度排序。
然后在只出现了一次的字符串中找出长度最长的一个，且这个字符串不是其他字符串的子串（在比它长的字符串里找即可）。
 */
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string,int> &a, pair<string,int> &b)
{
	return a.first.size() > b.first.size();
}

class Solution {
public:
	int findLUSlength(vector<string>& strs) {
		unordered_map<string,int> mymap;
        for(int i = 0; i < strs.size(); ++i)
          ++mymap[strs[i]];
        vector<pair<string,int>> myvec;
        for(auto it = mymap.begin(); it != mymap.end(); ++it)
           myvec.push_back(*it);
        sort(myvec.begin(),myvec.end(),cmp);
        for(int i = 0; i < myvec.size(); ++i)
        {
           if(myvec[i].second == 1){
               int j = 0;
               for(; j < i; ++j)
                 if(isS1subsOfS2(myvec[i].first,myvec[j].first))
                     break;
               if(j == i) return myvec[i].first.size();
           }
        }
        return -1;
    }

    bool isS1subsOfS2(string &s1, string &s2){
    	int j = 0, i = 0;
    	for(; i < s1.size(); ++i)
    	{
        	while(j<s2.size() && s1[i]!=s2[j]) ++j;
        	if(j == s2.size())
           		return false;
        	++j;
    	}
    	return true;
	}
};

int main()
{
	Solution s;
	vector<string> strs{"abc","cde","fed"};
	cout<<s.findLUSlength(strs)<<endl;
}

