/*
给出数字n，返回螺旋状的二维数组，元素从1到n^2。
*/

#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
#include <algorithm>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval a, Interval b)
{
	return a.start < b.start;
}

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), cmp);
		vector<Interval> result;
		Interval temp;
		for (int i = 0; i < intervals.size(); )
		{
			temp = intervals[i++];
			while (i<intervals.size() && temp.end>=intervals[i].start)
			{
				temp.start = min(temp.start, intervals[i].start);
				temp.end = max(temp.end, intervals[i].end);
				++i;
			}
			result.push_back(temp);
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<Interval> in{ { 1, 4 }, { 0, 1 }, { 8, 10 }, { 15, 18 } };
	//vector<Interval> in{ { 1, 4 }, { 2 , 3 } };
	vector<Interval> out = s.merge(in);
	for (int i = 0; i < out.size(); ++i)
	{
		cout << out[i].start << "," << out[i].end << endl;
	}
}

