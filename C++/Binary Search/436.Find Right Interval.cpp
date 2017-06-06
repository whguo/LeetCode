/*
给出一系列区间。针对每个区间，找出左边界大于等于它的右边界的区间中，有最小左边界的一个区间的下标。
没有找到返回-1。
[[1,4], [2,3], [3,4], [3,5]]
[1,4]没有满足条件的区间。[2,3]满足条件的区间为[3,4][3,5]，左边界最小的的[3,4]。
[3,4][4,5]没有满足条件的区间。所以返回[-1,2,-1,-1]。
*/
/*
思路：1.O(n^2)做法，对每个区间，遍历其他所有区间，找出比它右边界大的有最小左边界的区间。
		最后一个用例超时。
	2.使用有序的哈希表map，key为区间左边界，value为区间下标。插入后所有区间根据左边界排好序。
	然后对于每一个区间，在map中使用二分法找到第一个大于key的位置，然后结果为它的value值。
 */

#include <iostream>
#include <vector>
#include <limits.h>
#include <map>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<int> findRightInterval(vector<Interval>& intervals) {
		/*O(n^2)做法
		int length = intervals.size();
		if(length==0)	return vector<int> (0);
        vector<int>	result(length,-1);
        for(int i=0; i < length; ++i)
        {
        	int target = intervals[i].end, minleft = INT_MAX, minindex=-1;
        	for(int j=0; j < length; ++j)
        	{
        		if(i!=j && intervals[j].start>=target)
        		{
        			if (minleft > intervals[j].start)
					{
						minleft = intervals[j].start;
						minindex = j;
					}	
        		}
        	}
        	result[i] = (minleft==INT_MAX)? -1:minindex;
        }
        return result;*/

		map<int, int> mymap;
		int n = intervals.size();
        vector<int> result;  
        for (int i = 0; i < n; ++i)
            mymap[intervals[i].start] = i;
        for (auto in : intervals) {
            auto itr = mymap.lower_bound(in.end);
            if (itr == mymap.end()) result.push_back(-1);
            else result.push_back(itr->second);
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<Interval> intervals{{1,4},{2,3},{3,4},{3,5}};
	vector<int> out = s.findRightInterval(intervals);
	for(int n:out)
		cout<<n<<" ";
	cout<<endl;
}

