/*
一个字符串上多加一个字母形成另外一个字符串，找出多加的那个字母。
*/
/*
思路：可以用Map，也可以异或。
 */
#include <iostream>
#include <vector> 
#include <unordered_map>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        /*异或
        char r=0;
        for(char c:s) r ^=c;
        for(char c:t) r ^=c;
        return r;
         */

    	unordered_map<char,int>	mymap;
        for(auto ch:s)
        	++mymap[ch];
        for(auto ch:t)
        {
        	if(mymap.count(ch)==0 || mymap[ch]==0)
        		return ch;
        	else
        		--mymap[ch];
        }
    }
};
int main()
{
	Solution s;
	cout<<s.findTheDifference("a","aa")<<endl;
}

