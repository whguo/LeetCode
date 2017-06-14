/*
给出字符串数组words，找出最大的length(words[i])*length(words[j])
其中，两个字符串没有公共的字符。
*/
/*
思路：由于只有小写字母
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProduct(vector<string>& words) {
        vector<int> mask(words.size());
        int maxproduct = 0;
        for(int i=0; i < words.size(); ++i)
        {
        	for(char ch:words[i])
        		mask[i] |= 1 << (ch-'a');
        	for(int j=0; j < i; ++j)
        	{
        		if((mask[i] & mask[j])==0)	
        			maxproduct=max(maxproduct,int(words[i].size()*words[j].size()));
        	}
        }
        return maxproduct;
    }
};
int main()
{
	Solution s;
	vector<string> words{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	cout<<s.maxProduct(words)<<endl;
}

