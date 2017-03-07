/*
数组元素代表距离x轴的距离，这样形成一系列数组，求两条垂直线段和x轴能围成的最大容积。
*/
/*
思路：两个指针指头尾，更新最大容积，两个指针矮的向前挪。
 */
#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
#include <limits.h>
using namespace std;

class Solution {
public:
     int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1,maxarea = INT_MIN; 
        while(i < j)
        {
        	if(height[i]>=height[j])
        	{
        		maxarea = max(maxarea,(j-i)*height[j]);
        		--j;
        	}
        	else
        	{
        		maxarea = max(maxarea,(j-i)*height[i]);
        		++i;
        	}
        }
        return maxarea;
    }
};

int main()
{
	Solution s;
	vector<int> nums{5, 7, 2, 1};
	cout<<s.maxArea(nums)<<endl;
}

