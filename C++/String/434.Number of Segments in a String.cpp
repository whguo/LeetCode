/*
返回一个字符串被分成的段数，由空格分开。
*/
/*
思路：有递归的思想
 */
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
	int countSegments(string s) {
        int count = 0;
        s +=' ';     
        for(int i=1; i < s.length(); ++i)
        	if(s[i]==' ' && s[i-1]!=' ')	++count;
        return count;
    }
};

int main()
{
	Solution s;
	cout<<s.countSegments(" Hello, my  name is John");
}

