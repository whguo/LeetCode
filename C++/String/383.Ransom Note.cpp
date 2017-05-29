/*
给定两个字符串magazines和ransomNote，
问是否可以从magazines中抽取字母（每个字母只能用一次）组成ransomNote
*/
/*
思路：因为只有小写字母，所以可以使用vector代替Map。
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
        vector<int>	myvec(26);
        for(char ch:magazine)
        	++myvec[ch-'a'];
        for(char ch:ransomNote)
        {
        	--myvec[ch-'a'];
        	if(myvec[ch-'a'] < 0)	return false;
        }
        return true;
    }
};

int main()
{
	Solution s;;
	cout<<s.canConstruct("acxe","edeabco")<<endl;
}

