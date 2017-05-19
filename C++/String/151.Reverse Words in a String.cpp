/*
把一句话中按照单词逆序
*/
/*
思路：C++没有split函数
1.先把整个string逆转，然后对每个单词逆序
2.重新生成一个字符串，先遍历的单词放在后边。
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		string result;
        int start = 0;
        for (int i = 0; i < s.size(); i ++){
            if (s[i] == ' '){
                if (i > start )		//避免把单独的一个空格加进去
                    result = s.substr(start,i-start)+ " " + result;
                start = i + 1;
            }
            else if (i == s.size()-1)//把最后一个单词加进去
                result = s.substr(start,s.size()-start)+" "+result;
        }
        //result后边多加了一个空格，去掉
        s = result.substr(0,result.size()-1) ;
    }
};

int main()
{
	Solution s;
	s.reverseWords(ss);
	cout << ss << endl;
}