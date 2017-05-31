/*
实现整数的开方运算。
*/
/*
思路：二分法。n小于4时，n/2小于n的开方，n大于2时，n/2大于n的开方。
所以在n大于4时使用二分法，n/2为又边界。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
        if(x < 2)	return  x;
        if(x < 6)	return x/2;
        int l = 2, r = x/2;
        while(l < r)
        {
        	long long mid = (l + r) / 2 + 1;
        	long long pow = mid * mid;
        	if(pow == x)	return mid;
        	if(pow < x)	l = mid;
        	else r = mid-1;
        }
        return l;
    }
};

int main()
{
	Solution s;
	cout<<s.mySqrt(2147395599)<<endl;
}

