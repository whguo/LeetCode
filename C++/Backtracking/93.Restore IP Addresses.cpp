/*
给出数字字符串，返回这些字符串可能构成的ip地址。
例如：给出"25525511135"，返回["255.255.11.135", "255.255.111.35"]
*/
/*
思路：三层循环，中间穿插剪枝。
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		int length = s.length();
		vector<string> result;
		string first = "";
		// length - i > 3判断剩余的数是否够3个，不够的话不能成为IP
		for (int i = 0; i < 3 && length - i > 3; ++i)
		{
			if (i == 1 && s[0]=='0')	break;//判断是否是0打头的2位数，是的话可以跳出循环
			first += s[i];		
			if (length - i>10)	continue;//判断剩余的数是否大于9个，大于9个的话后边数字多余
			string second = "";	
			//判断是否是大于255的数
			if (i == 2 && (s[0]>'2') || (s[0] == '2' && (s[1]>'5' || s[1] == '5' && s[2]>'5')))  break;
			for (int j = 1; j < 4 && length - i - j > 2; ++j)
			{
				second += s[j + i];
				if (j == 2 && second[0]=='0')	break;
				if (length - j - i>7)	continue;	
				string third = "";
				if (j == 3 && (second[0]>'2') || (second[0] == '2' && (second[1]>'5' || second[1] == '5' && second[2]>'5')))  break;
				for (int k = 1; k < 4 && length - i - j - k > 1; ++k)
				{
					third += s[i + j + k];
					if (k == 2 && third[0]=='0')	break;
					if (length - i - j - k>4)	continue;
					if (k == 3 && (third[0]>'2') || (third[0] == '2' && (third[1]>'5' || third[1] == '5' && third[2]>'5')))  break;
					string forth = s.substr(i + j + k + 1);
					if(forth.length()>=2 && forth[0]=='0')	break;
					if (forth.length() == 3 && (forth[0]>'2') || (forth[0] == '2' && (forth[1]>'5' || forth[1] == '5' && forth[2]>'5')))  break;
					result.push_back(first + '.' + second + '.' + third + '.' + forth);
				}
			}
		}
		return result;
    }
};

int main()
{
	Solution s;
	vector<string> out = s.restoreIpAddresses("25525511135");
	//out = s.restoreIpAddresses("0000");
	//out = s.restoreIpAddresses("010010");
	//out = s.restoreIpAddresses("101023");
	//out = s.restoreIpAddresses("172162541");
	//out = s.restoreIpAddresses("28576");
	for(string str:out)
		cout<<str<<endl;
}