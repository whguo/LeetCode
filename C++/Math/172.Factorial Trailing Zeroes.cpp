/*
求n!末尾0的个数。
*/

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
        int result = 0;
        while(n)
        {
        	n /= 5;
        	result += n;
        }
        return result;
    }
};
int main()
{
	Solution s;
	cout<<s.trailingZeroes(130)<<endl;
}

