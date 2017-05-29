/*
打印字符串的全排列
*/
/*
思路：把字符串分为两个部分，一部分是第一个字符，另一部分是剩余字符，求剩余部分的全排列。
然后拿第一个字符和剩余的字符逐个交换（交换后往下递归，递归完再换回来。然后在跟下一个交换）。
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void Permutation(char* pstr)
	{
		if (pstr==NULL)	return;
		Permutation(pstr, pstr);
	}
	void Permutation(char* pStr, char* pBegin)
	{
		if (*pBegin == '\0')	cout << pStr << endl;
		else
		{
			for (char *pCh = pBegin; *pCh != '\0'; ++pCh)
			{
				char temp = *pCh;
				*pCh = *pBegin;
				*pBegin = temp;
				Permutation(pStr,pBegin+1);
				temp = *pCh;
				*pCh = *pBegin;
				*pBegin = temp;
			}
		}
	}
};

int main()
{
	Solution s;
	char ch[] = "abc";
	s.Permutation(ch);
	return 0;
}
