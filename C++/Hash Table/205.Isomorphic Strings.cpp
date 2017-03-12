/*
判断两个字符串是不是镜像的。
*/
/*
思路：需要两个map来记录，因为可能出现多对1的情况。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int m = s.size(), n = t.size();
		if (m != n)	return false;
		unordered_map<char, char>	mymap1,mymap2;
		for (int i = 0; i < m; ++i)
		{
			if (mymap1.count(s[i]) == 0)	
				mymap1[s[i]] = t[i];
				
			else
				if (mymap1[s[i]] != t[i])	return false;
			if (mymap2.count(t[i]) == 0)
				mymap2[t[i]] = s[i];
			else
				if (mymap2[t[i]] != s[i])	return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.isIsomorphic("ab", "aa") << endl;
}

