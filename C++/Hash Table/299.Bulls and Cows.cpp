/*
A代表两个字符串相同位置有相同的字符，B代表相同字符出现在不同位置
"1807"和"7810"，返回1A3B。
在不同位置只计数一次，"1123"和"0111"返回1A1B
*/
/*
思路：两个数组计数，记录除了相同的数外，每个数出现的次数。
B个数就是两个数组中出现次数较少的次数总和。
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <strstream>
#include <windows.h>
#include <windef.h>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
        vector<int>	myguess(10,0),mysecret(10,0);
        int a = 0, b = 0;
        for(int i=0; i < secret.size(); ++i)
        {
        	if(secret[i]==guess[i])
        		++a;
        	else
        	{
        		++mysecret[secret[i]-'0'];
        		++myguess[guess[i]-'0'];
        	}
        }
        for(int i=0; i < 10; ++i)
        {
        	b += min(myguess[i],mysecret[i]);
        }
        char result[20];
		sprintf(result, "%d%c%d%c", a,'A',b,'B');
        return string(result);
    }
};

int main()
{
	Solution s;
	cout << s.getHint("1123","0111") << endl;
}

