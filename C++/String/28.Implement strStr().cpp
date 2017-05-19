/*
求字符串中给定子串的位置，找不到为-1。
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int>	nextval;
	int strStr(string haystack, string needle) {

		//简单做法，O(m*n)
        /*int m = haystack.size(), n = needle.size();
        if(!n)	return 0;
        for(int i=0; i <= m-n; ++i)
        {
        	int j = 0;
        	for( ; j < n ; ++j)
        	{
        		if(haystack[i+j] != needle[j])	break;
        	}
        	if(j==n)	return i;
        }
        return -1;*/

        //KMP算法
        int m = haystack.size(), n = needle.size();
        if(!n)	return 0;
        getnext(needle);
        for(int i=0,j=0; i < m;)
        {
        	if(haystack[i] == needle[j])	++i,++j;
        	if(j==n)	return i-j;
        	if(i < m && haystack[i] != needle[j])
        	{
        		if(j)	j = nextval[j-1];
        		else i++;
        	}
        }
        return -1;
    }
    void getnext(string pattern)
    {
    	int n = pattern.size();
        nextval.resize(n,0);
        for(int i=1,len=0; i < n;)
        {
        //example "abababca" and i==5, len==3. The longest prefix suffix is "aba", when pat[i]==pat[len],
         //we get new prefix "abab" and new suffix "abab", so increase length of  current nextval by 1 and go to next iteration. 
         if (pattern[i] == pattern[len])
         {
           nextval[i] = ++len;
           i++;
         }
         else // (pat[i] != pat[len])
         {
           if (len)
           {
             len = nextval[len-1];
             //This is tricky. Consider the example "ababe......ababc", i is index of 'c', len==4. The longest prefix suffix is "abab",
             //when pat[i]!=pat[len], we get new prefix "ababe" and suffix "ababc", which are not equal. 
             //This means we can't increment length of nextval based on current nextval "abab" with len==4. We may want to increment it based on
             //the longest prefix suffix with length < len==4, which by definition is nextval of "abab". So we set len to nextval[len-1],
             //which is 2, now the nextval is "ab". Then check pat[i]==pat[len] again due to the while loop, which is also the reason
             //why we do not increment i here. The iteration of i terminate until len==0 (didn't find nextval ends with pat[i]) or found
             //a nextval ends with pat[i].
           }
           else // if (len == 0)
           { // there isn't any nextval ends with pat[i], so set nextval[i] = 0 and go to next iteration.
             nextval[i++] = 0;
           }
        }
       } 
    }
};
int main()
{
	Solution s;
	cout << s.strStr("abcdabcdddade","dabd") << endl;
}

