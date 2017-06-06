/*
给定一组排列在水平线上的房屋和加热器，计算最小的加热器半径，使得所有房屋都可以被覆盖。
输入房屋和加热器的坐标（均不一定有序），输出期望的加热器半径的最小值。
1.房屋和加热器的数目均为非负整数，并且不大于25000
2.房屋和加热器的位置是非负整数，并且不超过10^9
3.位于加热器半径范围内的房屋均可被加热
4.加热器的半径都是一样的
*/
/*
思路：houses和heaters都不是有序的，所以先对heaters排序，然后找到每一个house
在heaters中所处的区间位置，然后计算更新最大的距离。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int minradius = INT_MIN;
        for(int house:houses)
        {
        	//找到每个house在heaters的位置
        	int left = 0, right = heaters.size()-1, mid;
        	while(left <= right)
        	{
        		mid = (left+right)/2;
        		if(heaters[mid]>=house) right = mid-1;
        		else left = mid+1;
        	}

        	//因为这是计算每个house左边和右边最近的heater距离，所以house在最左或最右时，距离为INT_MAX.
        	int leftdist = (left>=1)? house-heaters[left-1]:INT_MAX;
        	int rigthdist = (left<heaters.size())? heaters[left]-house:INT_MAX;
        	minradius = max(minradius,min(leftdist,rigthdist));
        }
        return minradius;
    }

    //两个排序，然后线性寻找
    /*if (heaters.size() == 0)	return 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        int index = 0;
        for (int i = 0; i < houses.size(); i++) {
            while (index + 1 < heaters.size() && (abs(heaters[index+1] - houses[i]) <= abs(heaters[index] - houses[i]))) {
                index++;
            }
            radius = max(radius, abs(heaters[index] - houses[i]));
        }
        return radius;*/
};

int main()
{
	Solution s;
	vector<int> houses{1,2,3,4,5,6,7,9};
	vector<int> heaters{1,3,9};
	cout<<s.findRadius(houses,heaters)<<endl;
}

