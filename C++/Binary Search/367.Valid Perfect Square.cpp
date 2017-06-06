/*
判断一个数是否是完全平方数。
*/
/*
思路：使用二分法计算平方是否大于给定数。
 */

#include <iostream>
using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		int left = 1, right = num;
		while(left <= right)
		{
			long mid = left + (right - left)/2;// long类型防止2147483647用例
			long square = mid*mid;
			if(square == num)	return true;
			else if(square > num)	right = mid-1;
			else left = mid+1;
		}
		return false;
    }
};

int main()
{
	Solution s;
	cout<<s.isPerfectSquare(256)<<endl;
}

