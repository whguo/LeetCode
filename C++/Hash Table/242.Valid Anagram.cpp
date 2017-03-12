/*
判断两个字符串是否是“相同字符异序词”
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
        unordered_map<char,int>		mymap1,mymap2;
        for(int i=0; i < s.size(); ++i)
        {
        	if(mymap1.count(s[i])==0)
        		mymap1[s[i]]=0;
        	else
        		++mymap1[s[i]];
        	if(mymap2.count(t[i])==0)
        		mymap2[t[i]]=0;
        	else
        		++mymap2[t[i]];
        }
        return mymap1==mymap2 && s.size()==t.size();
    }
};

int main()
{
	Solution s;
	cout << s.isAnagram("anagram","nagaram") << endl;
}

