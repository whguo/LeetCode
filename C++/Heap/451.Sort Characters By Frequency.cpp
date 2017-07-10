/*
字符串中按字母出现的频率排序
*/
/*
思路：先用map记录每个字母出现的频率，然后生成一个长度为s.length的字符串数组，
      出现频率为k的字母，在数组第k个位置重复插入k个字母
      最后数组从后向前把字符串累计起来。
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

