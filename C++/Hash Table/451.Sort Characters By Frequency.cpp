/*
字符串中按字母出现的频率排序
*/
#include <iostream>
#include <vector> 
#include <unordered_map>
using namespace std;


class Solution {
public:
    string frequencySort(string s) {
    	string result;
        unordered_map<char,int>	mymap;
        for(char ch:s)	++mymap[ch];
        vector<string> myvec(s.size()+1,"");
        for(auto it:mymap)
        {
        	//append(n,c)连续插入n个c
        	myvec[it.second].append(it.second,it.first);
        }
        for(int i=s.size(); i > 0; --i)
        {
        	if(myvec[i]!="")	result.append(myvec[i]);
        }
        return result;
    }
};
int main()
{
	Solution s;
	cout<<s.frequencySort("tree")<<endl;

}

