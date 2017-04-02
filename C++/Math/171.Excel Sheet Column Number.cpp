/*
字符串转换成整数。
	A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
        int result = 0;
        for(char ch:s)
        {
            result = result*26+(ch-'A'+1);
        }
        return result;
    }
};
int main()
{
	Solution s;
	cout<<s.titleToNumber("ABC")<<endl;
}

