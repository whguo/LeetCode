/*
判断一个数是不是Perfect Number。
指，它的所有因数（除本身）的和与本身是不是相等。
*/
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	bool checkPerfectNumber(int num) {
		if(num==1)  return false;
		int perfectsum = 1;
        for(int i=2; i < sqrt(num); ++i)
        {
        	if(num%i==0)
        	{
        		perfectsum += i;
        		perfectsum += num/i;
        	}
        }
        return num==perfectsum;
    }
};
int main()
{
	Solution s;
	cout << s.checkPerfectNumber(28) << endl;
}

