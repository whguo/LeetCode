/*
判断一个字符串是否符合某种模式
如：给出模式abbb,那么字符串"dog cat cat dog"满足，而"dog cat cat fish"不满足
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <cstring>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {

		unordered_map<char,int>	charmap;
		unordered_map<string,int>	stringmap;
		stringstream ss(str);
		string temp;
		int i = 0 , n = pattern.size();
		while(getline(ss, temp, ' ')) 
		{
			if(i==n || charmap[pattern[i]]!=stringmap[temp])
				return false;
			charmap[pattern[i]] = stringmap[temp] = i+1;
			++i;
		}
		return i==n;

		/*以下做法解决不了多对一问题。
        stringstream ss(str);
        string temp;
        unordered_map<char,string>	mymap;
        int i = 0;
        while(getline(ss, temp, ' ')) 
        {
         	if(mymap.count(pattern[i])==0)
         		mymap[pattern[i]] = temp;
         	else
         		if(mymap[pattern[i]]!=temp)	return false;
         	++i;
        }
        return i==pattern.size();*/
    }
};

int main()
{
	Solution s;
	cout << s.wordPattern("abba","dog cat cat dog") << endl;
}

