/*
猜测数的大小。数为从1到n，猜测别人挑选的是哪个。
每次调用API函数guess，告诉挑选的数与答案的大小比较。
-1表示别人的数小。1表示别人的数大。0表示猜对了。
*/
/*
思路：二分法。
 */

#include <iostream>
using namespace std;

class Solution {
public:
	int guessNumber(int n) {
        int l = 1, r = n;
        while(l <= r)
        {
        	int mid = l + (r - l)/2;
        	int res = guess(mid);
        	if(res == 0)	return mid;
        	else if(res==1)	l = mid+1;
        	else r = mid-1;
        }
        return -1;
    }
};

int main()
{
	Solution s;
	cout<<s.guessNumber(256)<<endl;
}

