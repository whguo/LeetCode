/*
判断一个数是否是完全平方数。不能使用库函数如sqrt。
*/
/*
思路：1.所有完全平方数都可表示为1+3+5+7+...
2.二分法
*/
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		int i = 1;
     	while (num > 0)
     	{
         	num -= i;
         	i += 2;
     	}
     	return num == 0;
     	
		/*二分法
        if (num < 1) return false;
        long left = 1, right = num;// long type to avoid 2147483647 case
    
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long t = mid * mid;
            if (t > num)
                right = mid - 1;
            else if (t < num)
                left = mid + 1;
            else    return true;
      }
      return false;*/
    }
};
int main()
{
	Solution s;
	cout << s.isPerfectSquare(81) << endl;
}

