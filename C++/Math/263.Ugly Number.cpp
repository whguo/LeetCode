/*
判断一个数是否是Ugly Number，定义为因数只包含2,3,5的。
特殊的，1是Ugly Number。
*/

#include <iostream>
using namespace std;

class Solution {
public:
	bool isUgly(int num) {
        if (num==0) return false;
        while (num%2==0)     num /= 2;
        while (num%3==0)     num /= 3;
        while (num%5==0)     num /= 5;
        return num==1;
    }
};
int main()
{
	Solution s;
	cout<<s.isUgly(12345)<<endl;
}

