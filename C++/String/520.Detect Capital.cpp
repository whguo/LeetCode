/*
给出一个单词，判断是否正确使用了大写字母。
要么单词全大写，要么全小写，要么只有第一个大写。
*/
/*
思路：判断第一个和第二个字母，即可知道后续字母应该为大写还是小写。
 */
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		int length = word.length();
		if (length<2)	return true;
		int first = isupper(word[0]);
		int second = isupper(word[1]);
		if (!first && second)	return false;
		for (int i = 2; i < length; ++i)
		{
			if (isupper(word[i]) ^ second)	return false;
		}
		return true;
    }
};

int main()
{
	Solution s;
	cout<<s.detectCapitalUse("FlaG")<<endl;
	cout<<s.detectCapitalUse("Flag")<<endl;
	cout<<s.detectCapitalUse("flag")<<endl;
	cout<<s.detectCapitalUse("FLAG")<<endl;
}

