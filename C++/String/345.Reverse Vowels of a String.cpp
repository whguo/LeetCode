/*
将一个字符串中的元音字母aeiou逆序其他的不动。
*/
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
        for(int i=0,j=s.size()-1; i < j; ++i, --j)
        {
        	while(i < j && !isvowel(s[i]))	++i;
        	while(i < j && !isvowel(s[j]))	--j;
        	char tmp = s[i];
        	s[i] = s[j] , s[j] = tmp;
        }
        return s;
    }
    bool isvowel(char ch)
    {
    	if(ch=='a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
    	   ch=='A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    		
    		return true;
    	return false;
    }
};

int main()
{
	Solution s;;
	cout<<s.reverseVowels("A man, a plan, a canal: Panama")<<endl;
}

