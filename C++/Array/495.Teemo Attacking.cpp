/*
从时间数组给出的时间投毒，每次持续时间为duration。
在持续时间内投毒并不叠加，只是时间更新。
求总的中毒时间。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    	int lenth = timeSeries.size();
    	if(lenth<=0)	return 0;
    	int totalTime = 0;
    	for(int i= 0; i < lenth-1; ++i)
    	{
			int dis = timeSeries[i+1]-timeSeries[i];
    	    totalTime += (dis<duration? dis:duration);
    	}
    	totalTime += duration;
        return totalTime;
    }
};

int main()
{
	Solution s;
	vector<int> time;
	time.push_back(1);
	time.push_back(2);
	cout<<s.findPoisonedDuration(time,2);
}