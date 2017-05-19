/*
将罗马数字转换为整数。
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char,int>	mymap{{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
		int result = mymap[s.back()], length = s.size();
		for(int i=0; i < length-1; ++i)
		{
			if(mymap[s[i]]<mymap[s[i+1]])
				result -= mymap[s[i]];
			else
				result += mymap[s[i]];
		}
		return result;
    }
};
int main()
{
	Solution s;
 	cout<<s.romanToInt("MCMLXXX");
}

