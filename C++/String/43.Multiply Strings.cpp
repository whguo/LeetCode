/*
两个字符串代表两个非负整数，求两个数的积。
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		vector<string>	strvec;
		string result = "";
		for (int i = num1.size() - 1; i >= 0; --i)
		{
			string temp = "";
			int flag = 0, multi;
			for (int j = num2.size() - 1; j >= 0; --j)
			{
				multi = (num1[i] - '0')*(num2[j] - '0') + flag;
				temp += char(multi % 10 + '0');
				flag = multi / 10;
			}
			temp = (flag == 0) ? temp : (temp + char(flag + '0'));
			strvec.push_back(temp);
		}
		int flag = 0, sum, n = strvec.size() + strvec.back().length() - 1;
		for (int i = 0; i < n; ++i)
		{
			sum = flag;
			for (int j = 0; j <= i && j<strvec.size(); ++j)
			{
				if (i - j<strvec[j].size())
					sum += (strvec[j][i - j] - '0');
			}
			result = char(sum % 10 + '0') + result;
			flag = sum / 10;
		}
		//最后一个进位
		if(flag != 0) result = char(flag + '0')+result;
		//去掉前面的0
		int pos = result.find_first_not_of('0');
		return (pos==-1)? "0" : result.substr(pos);
	}
};
int main()
{
	Solution s;
	cout<< s.multiply("15", "112")<<endl;
}

