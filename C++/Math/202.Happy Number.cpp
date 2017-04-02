/*
HappyNumber，给一个多位数，循环做每位数平方相加，能得到结果1，则是happynumber。
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:

	//发现2--6都是非happynumber，所有的非happynumber最终会进入这个循环。
	bool isHappy(int n) 
	{
		while(n>6)
		{
        	int next = 0;
        	while(n){next+=(n%10)*(n%10); n/=10;}
        	n = next;
    	}
    	return n==1;
	}

	/*使用set
	bool isHappy(int n) {
		unordered_set<int>	myset;
        while(1)
        {
        	int sum = 0,tmp = n;
        	while(tmp>0)
        	{
        		sum += (tmp%10)*(tmp%10);
        		tmp = tmp/10;
        	}
        	if(sum==1)	return 1;
        	if (myset.find(sum)!=myset.end())	return false;
			else
				myset.insert(sum);
			n = sum;
        }
    }*/
};

int main()
{
	Solution s;
	cout<<s.isHappy(82)<<endl;
}

