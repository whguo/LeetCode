/*
判断一个数是不是2的次方
*/
/*
思路：n&n-1是否为0。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
        if(n<=0)    return false;
        return (n&(n-1))==0;
    }
};

int main()
{
	Solution s;	
	cout << s.isPowerOfTwo(256) <<endl;
}

