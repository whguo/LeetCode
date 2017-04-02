/*
判断一个整型数是不是回文的。
*/
/*
思路：取得后一半和前一半比较。
 */
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		//负数和0结尾的数一定不是回文的。
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};
int main()
{
	Solution s;
 	cout<<s.isPalindrome(123);
}

