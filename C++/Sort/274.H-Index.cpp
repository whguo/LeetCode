/*
H-Index,找一个数h，使得数组中有h个数大于等于它，剩余的小于它
注意：如果存在多个可能的h值，取最大值作为h指数。
*/
/*
思路：先排序，然后从后向前遍历，寻找某个数，使得它小于它后边的长度。
然后返回它后边长度-1。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(),citations.end());
        int length = citations.size();
        for(int i=length-1; i >= 0 ; --i)
        {
        	if(citations[i] <= length-i-1)
        		return length-i-1;
        }
        return length;
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,3,1};
	cout << s.hIndex(nums) << endl;
}

