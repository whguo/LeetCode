/*
H-Index,找一个数h，使得数组中有h个数大于等于它，剩余的小于它
注意：如果存在多个可能的h值，取最大值作为h指数。
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		//O(n)方法，开辟长度为n的数组
		int len = citations.size();
    	vector<int> count(len+1,0);
    
    	for (int c: citations)
        	if (c > len) 
            	count[len]++;
        	else 
            	count[c]++;
    
    
    	int total = 0;
    	for (int i = len; i >= 0; i--) {
        	total += count[i];
        	if (total >= i)
            	return i;
    	}
    
    	return 0;

		/*O(NlogN)方法
		int length = citations.size();
		if(length==0)	return 0;
        multiset<int> 	myset;
        for(int i=0; i < length; ++i)
        {
        	myset.insert(citations[i]);
        }
        int i = 0;
        for(multiset<int>::reverse_iterator it=myset.rbegin(); it != myset.rend(); ++it,++i)
        {
        	if(*it<=i)	return i;
        }
        return length;*/
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,3,1};
	cout << s.hIndex(nums) << endl;
}

