/*
将整数转换为罗马数字。
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
        vector<vector<string>> myvec({{"","I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
    								{"","X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
    								{"","C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
    								{"","M", "MM", "MMM", "  ", " ", "  ", "   ", "    ", "  "}});
        string result;
        int index = 0;
        while(num)
        {
        	result = myvec[index][num%10] + result;
        	num /= 10 , ++index;
        }
        return result;
    }
};
int main()
{
	Solution s;
 	cout<<s.intToRoman(1980);
}

