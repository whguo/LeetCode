/*
英语单词的0-9数字，字母顺序打乱，返回字符串中的数字，按照升序方式。
输入永远合法。
*/
/*
思路：0独有字母z，2独有w，4独有u，6独有x，8独有g。
 */
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
	string originalDigits(string s) {
        vector<int>		count(10);
        string result = "";
        for(char ch:s)
        {
        	switch(ch)
        	{
        		case 'z':
        			++count[0];	break;
        		case 'w':
        			++count[2];	break;
        		case 'u':
        			++count[4];	break;
        		case 'x':
        			++count[6]; break;
        		case 'g':
        			++count[8];	break;
        		case 's':
        			++count[7];	break;//7-6
        		case 'f':
        			++count[5];	break;//5-4
        		case 'h':
        			++count[3];	break;//3-8
        		case 'i':
        			++count[9];	break;//9-8-5-6
        		case 'o':
        			++count[1];	break;//1-0-2-4
        	}
        }
        count[7] -= count[6];	count[5] -= count[4];	count[3] -= count[8];
        count[9] = count[9] - count[8] - count[5] - count[6];
        count[1] = count[1] - count[0] - count[2] - count[4];
        for(int i=0; i < 10; ++i)
        {
        	cout<<count[i]<<endl;
        	for(int j=0; j < count[i]; ++j)
        		result += char(i+'0');
        }
        return result;
    }
};
int main()
{
	Solution s;
	cout << s.originalDigits("nnei") << endl;
}

