/*
调用API函数isBadVersion寻找所有版本中第一次出现错误的版本。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right)
        {
        	int mid = left + (right-left)/2;
        	if(isBadVersion(mid))	right = mid;
        	else left = mid + 1;
        }
        return left;
    }
};

int main()
{
	Solution s;
	cout << s.firstBadVersion(10) << endl;
}

