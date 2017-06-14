/*
把整数转换为16进制的数，字母都小写。（负数用补码）
*/
/*
思路：计算每4位是多少，然后加到字符串上。
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	string toHex(int num) {
		/*一位一位计算，太复杂
        int n = (num >= 0) ? num : (num & 0x7fffffff);
		int i = 0, j = 7, nums[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		vector<char> hex{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
		while (n)
		{
			nums[i >> 2] += (n & 1) << (i % 4);
			n >>= 1;
			++i;
		}
		if(num < 0) nums[7] += 8;
		string result = "";
		while (nums[j] == 0) --j;
		while (j >= 0)	result += hex[nums[j--]];
		return result;*/

		//4位4位的计算
		string HEX = "0123456789abcdef";
		if (num == 0) return "0";
        string result;
        int count = 0;
        while (num && count++ < 8) 
        {
            result = HEX[(num & 0xf)] + result;
            num >>= 4;
        }
        return result;
    }
};
int main()
{
	Solution s;
	cout << s.toHex(-1) <<endl;
}

