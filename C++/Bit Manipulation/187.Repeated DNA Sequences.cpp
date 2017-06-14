/*
找出DNA串中重复出现的长度为10的序列。
*/
/*
思路：1.使用unordered_map把每个长度为10的序列记下来。重复出现就加到结果中。
2.使用思路1会占用太多的内存空间，可能 会超过限制。所以考虑使用更少的空间表示这10个字符。
因为只有ACGT四个字母,ASCII码的值分别为A:0x41,C:0x43,G:0x47,T:0x54
用二进制最后三位可以对这四个数进行区分。10个字符用30个二进制即可表示，考虑使用1个int。
每次挪到一个字符，整数向左移3位，与0x3fffffff与运算，即可得到该字符串对应的整数。
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> mymap;
        vector<string> result;
        int i = 0, n = 0, length = s.size();
        while(i < 9)
        	n = n<<3 | s[i++]&7;   //s[i]&7是s[i]这个字符对应的3位二进制数。
        while(i < length)
        //n先左移3位，和0x3fffffff与后得到当前9个字符对应的数，再和s[i]&7或运算得到这10个字符对应的int数
        	if(mymap[n = n<<3 & 0x3fffffff | s[i++]&7]++ == 1)
        		result.push_back(s.substr(i-10,10));
        return result;
    }
};

int main()
{
	Solution s;	
	vector<string> out = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for(string s:out)
		cout<<s<<endl;
}

