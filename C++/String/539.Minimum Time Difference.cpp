/*
给出一系列24小时制的时间，求任意两个时间相差的分钟数最小值。
*/
/*
思路：先把所有时间距离00:00的分钟数取出来，然后排序。分别做差求出最小的差。
最后再算最小的减最大的加上24*60。
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		int length = timePoints.size();
		if(length<2)	return 0;
        char ch;
        int h,m,mintime = INT_MAX; 
        vector<int>	minutes(length);
        istringstream is;  
        for(int i=0; i < length; ++i)
        {
        	is.clear();
        	is.str(timePoints[i]);
        	is >> h>> ch >> m;
        	minutes[i] = h*60+m;	
        }
        sort(minutes.begin(),minutes.end());
        for(int i=0; i < length-1; ++i)
        {
			mintime = min(mintime,minutes[i+1]-minutes[i]);
        }
        mintime = min(mintime,minutes[0]-minutes[length-1]+1440);
        return mintime;
    }
};

int main()
{
	Solution s;
	vector<string> strs{"11:59","00:00","10:10"};
	cout<<s.findMinDifference(strs)<<endl;
}

