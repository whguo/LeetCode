/*
一串序列，按照读法一直往下顺延，如下：
1, 11, 21, 1211, 111221, 312211, 13112221, 1113213211, 31131211131221 ...
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
返回第n个数。
*/
/*
思路：每次循环找连续相同的数。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string result = "1";
        for(int i=1; i < n; ++i)
        {
        	string tmp = "";
        	int count = 1;
        	for(int i=1; i < result.length(); ++i)
        	{
        		if(result[i]==result[i-1])
        		{
        			++count;
        			continue;
        		}
        		tmp = tmp + char(count+'0')+result[i-1];
        		count = 1;
        	} 
        	result = (tmp+char(count+'0')+result[result.length()-1]);
        }
        return result;
    }
};

int main()
{
	Solution s;;
	cout<<s.countAndSay(1)<<endl;
	cout<<s.countAndSay(2)<<endl;
	cout<<s.countAndSay(3)<<endl;
	cout<<s.countAndSay(4)<<endl;
	cout<<s.countAndSay(5)<<endl;
	cout<<s.countAndSay(6)<<endl;
	cout<<s.countAndSay(7)<<endl;
	cout<<s.countAndSay(8)<<endl;
}

