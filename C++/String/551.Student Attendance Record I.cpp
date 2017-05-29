/*
一个学生的出勤情况用A、L、P分别表示缺课、迟到、出勤。
如果一个学生少于一个缺课且少于两个连续的迟到，则可以被嘉奖。
问一个学生是否可以嘉奖。
*/
/*
思路：记录缺课次数，以及连续迟到次数。到次数则直接返回。
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool checkRecord(string s) {
        int absent=0, continuouslate=0;
        for(char ch:s)
        {
        	if(ch=='L') 
        	{
        		++continuouslate;
        		if(continuouslate==3)	return false;
        		continue;
        	}
        	if(ch=='A')
        	{	
        		++absent;
        		if(absent==2)	return false;
        	}
        	continuouslate = 0;
        }
        return true;
    }
};

int main()
{
	Solution s;
	cout<<s.checkRecord("PPALLP")<<endl;
	cout<<s.checkRecord("PPALLL")<<endl;
	cout<<s.checkRecord("LALL")<<endl;
}

