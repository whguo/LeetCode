/*
找到第n个Ugly Number，定义为因数只包含2,3,5的。
特殊的，1是Ugly Number。n不超过1690。
*/
/*
思路：存下来前面的数，每次从前面找数比较。
不能i,j,j每次加1，这样i加到7时出错，14不是。
 */
#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
        vector<int>	nums(n);
        nums[0] = 1;
        int i = 0, j = 0, k = 0 ,x,y,z,tmp;
        for(int p=1; p < n; ++p)
        {
        	x = nums[i]*2, y = nums[j]*3, z = nums[k]*5;
        	tmp = min(x,min(y,z));
        	if(tmp == x)	++i;
        	if(tmp == y)	++j;
        	if(tmp == z)	++k;
        	nums[p] = tmp;
        }
        return nums[n-1];
    }
};
int main()
{
	Solution s;
	cout<<s.nthUglyNumber(11)<<endl;
}

