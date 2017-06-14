/*
两个只包含小写字母的字符串，一长一短只差一个字母。找出这个字母。
*/
/*
思路：遍历两个字符串异或即可。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
        char r=0;
        for(char c:s) r ^=c;
        for(char c:t) r ^=c;
        return r;
    }
};
int main()
{
	Solution s;
	cout<<s.findTheDifference("abcd","abecd")<<endl;
}

