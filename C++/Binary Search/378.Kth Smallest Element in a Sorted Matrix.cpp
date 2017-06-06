/*
返回n*n二维数组中的第k小的数。
二维数组每行每列有序。
*/
/*
思路：1.使用优先级队列，维持最小的k个数。最后返回top即可。
2.使用二分法搜索。设置左上角和右下角的数为起始边界，求出中点，然后统计比中点小的数的个数。
如果个数小于k，那么中点需要变大，left=mid+1。否则right=mid，因为可能有重复的值，所以不能减1。
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
        /*优先级队列
        priority_queue<int> myqueue;
        for(auto row:matrix)
        {
        	for(auto n:row)
        	{
        		myqueue.push(n);
        		if(myqueue.size()>k)	myqueue.pop();
        	}
        }
        return myqueue.top();*/

        //二分法
        int n = matrix.size(), left = matrix[0][0], right = matrix[n-1][n-1],mid;
        while(left < right)
        {
        	mid = left + (right-left)/2;
        	int num = 0;
        	for(int i=0; i < n; ++i)
        	{
        		int pos = upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        		num += pos;
        	}
        	if(num<k)	left = mid + 1;
        	else right = mid;
        }
        return left;
    }
};

int main()
{
	Solution s;
	vector<vector<int>> nums{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24}};
	cout<<s.kthSmallest(nums,12)<<endl;
}

