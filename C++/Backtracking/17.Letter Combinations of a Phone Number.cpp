/*
列出字符串数对应9按键键盘字母的所有组合。
*/
/*
思路：每次遍历上一个结果，在末尾添加当前数字对应的字母，产生新的结果
	然后和当前结果交换。所以初始为一个空的字符串""。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		int length = digits.length();
   		vector<string> result;
   		if(length==0)	return result;
        static const vector<string>	myvec{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        result.push_back("");
   		for(int i=0; i < length; ++i)
   		{
   			int num = digits[i]-'0';
   			if(num<0 || num>9)	break;
   			const string& candidate = myvec[num];
   			if(candidate.length()==0)	continue;
   			vector<string> tmp;
   			for(int j=0; j < candidate.length(); ++j)
   			{
   				for(int k=0; k < result.size(); ++k)
   				{
   					tmp.push_back(result[k]+candidate[j]);
   				}
   			}
   			result.swap(tmp);
   		}
   		return result;
    }
};

int main()
{
	Solution s;;
	vector<string> re = s.letterCombinations("23");
	for(string str:re)
		cout<<str<<endl;
}

