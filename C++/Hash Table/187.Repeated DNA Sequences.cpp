/*
寻找重复出现的长度为10的DNA序列
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mymap;
        vector<string> result;
        int length = s.size();
        if(length<10)	return result;
        for(int i=0; i < length-10; ++i)
        {
        	//substr第一个参数起始下标，第二个参数是长度，不是结束下标。
        	string str=s.substr(i,10);
        	if(mymap.find(str)==mymap.end())
        	{
        		mymap[str] = 0;
        	}
        	else
        	{
        		++mymap[str];
        		if(mymap[str]==1)	result.push_back(str);
        	}
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<string> out;
	out = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for(int i=0; i < out.size(); ++i)
	{
		cout<<out[i]<<endl;
	}
}

