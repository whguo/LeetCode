/*
在字符串s中寻找字符串t字母任意顺序组成的串，返回所有起始下标。
字符串只包含字母。
*/

#include <iostream>
#include <vector> 
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result,svec(26,0),pvec(26,0);    
        int m = s.length(), n = p.length();
        if(m<n)	return result;
        for(int i=0; i < n; ++i)
        {
        	++pvec[p[i]-'a'];
        	++svec[s[i]-'a'];
        }
        if(pvec==svec)	result.push_back(0);
        for(int i=n; i < m; ++i)
        {
        	++svec[s[i]-'a'];
        	--svec[s[i-n]-'a'];
        	if(svec==pvec)	result.push_back(i-n+1);
        }
        return result;
    }
};
int main()
{
	Solution s;
	vector<int> r;
	r = s.findAnagrams("cbaebabacd","abc");
	for(int i:r)
	{
		cout<<i<<endl;
	}
}

