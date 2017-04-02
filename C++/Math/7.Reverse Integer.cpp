/*
翻转一个整型数。
32位，越界返回0。
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int flag = x<0? -1:1;
        vector<int>  num;
        x = abs(x);
        while(x>0)
        {
            num.push_back(x%10);
            x /= 10;
        }
        int n = num.size(),result = 0;
        for(int i=0; i < n-1; ++i)
        {
            result *= 10;
            result += num[i];   
        }
        if(result > 214748364)  return 0;
        else if(result == 214748364 && !(num[n-1]<=7))
            return 0;

        return n > 0 ? flag * (result*10 + num[n-1]) : 0;
    }
};
int main()
{
	Solution s;
 	cout<<s.reverse(-1234);
}

