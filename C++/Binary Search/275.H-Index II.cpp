/*
H-Index,找一个数h，使得有序数组中有h个数大于等于它，剩余的小于它
注意：如果存在多个可能的h值，取最大值作为h指数。
*/
/*
思路：二分法。
citations[mid] == len-mid，表示有citations[mid]个数大于等于citations[mid]。
citations[mid] > len-mid，表示有小于citations[mid]个数大于等于citations[mid]，向左移。
citations[mid] < len-mid，表示有大于citations[mid]个数大于等于citations[mid]，向右移。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int length = citations.size();	
        int left = 0, right = length-1 , mid;
        while(left <= right)
        {
        	mid = (left + right)/2;
        	if(citations[mid] == length-mid)	return citations[mid];
        	else if(citations[mid] > length-mid)	right = mid - 1;
        	else left = mid+1;
        }
        return length-left;
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,3,1};
	cout << s.hIndex(nums) << endl;
}

