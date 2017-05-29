/*
将一个字符串逆转。
*/
/*
思路：新建一个string，不用换位置，但是新的string要每个char都赋值，最后仍然慢。
调用swap函数，函数内部还是这样写的。所以直接写互换就好。
 */
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	string reverseString(string s) {
        int i = 0, j = s.size()-1;
        while(i<j)
        {
        	char tmp = s[i];
        	s[i++] = s[j];
        	s[j--] = tmp; 
        }
        return s;
    }
};

int main()
{
	Solution s;;
	cout<<s.reverseString("A man, a plan, a canal: Panama")<<endl;
}

