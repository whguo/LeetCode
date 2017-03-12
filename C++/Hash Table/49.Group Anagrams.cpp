/*
将一组字符串分类，拥有相同字母的分为一组。
*/
/*
思路：组合使用map和set。这里要用unordered_mitiset，因为可以有重复的字符串。
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,unordered_multiset<string>> mymap;
        for(string s:strs)
        {
        	string tmp = s;
        	sort(tmp.begin(), tmp.end());
        	mymap[tmp].insert(s);
        }
        for(auto m:mymap)
        {
        	vector<string>  temp(m.second.begin(),m.second.end());
        	result.push_back(temp);
        }
        return result;
    }

};

int main()
{
	Solution s;
	vector<string> board{ "eat" ,  "tea" ,  "tan" ,  "ate" ,  "nat" ,  "bat" };
	vector<vector<string>> out;
	out=s.groupAnagrams(board);
	for(int i=0; i < out.size(); ++i)
	{
		for(int j=0; j < out[i].size(); ++j)
		{
			cout<<out[i][j]<<"\t";
		}
		cout<<endl;
	}
}

