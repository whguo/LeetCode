/*
给出一组坐标点，求出所有的坐标组(i,j,k)，点i到点j和k的距离相同。
i,j,k的顺序是有关系的。比如给出[[0,0],[1,0],[2,0]]，返回2,两个分别是
[[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]。
*/
/*
思路：暴力解，对每个点求剩余点到它的距离，然后用Map存，距离为Key，得到到该点距离相等的数量。
 */
#include <iostream>
#include <vector> 
#include <unordered_map>
#include <utility>
using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
    	int result = 0 , length = points.size();
        for(int i=0; i < length; ++i)
        {
        	unordered_map<int,int>	mymap;
        	for(int j = 0; j < length; ++j)
        	{
        		if(i != j)
        		{
        			int dis = distance(points[i],points[j]);
        			++mymap[dis];
        		}
        	}
        	for(auto it:mymap)
        	{
        		if(it.second>1)	result += it.second*(it.second-1);
        	}
        }
        return result;
    }
    int distance(pair<int,int> A,pair<int,int> B)
    {
    	int x = A.first - B.first;
    	int y = A.second - B.second;
    	return x*x+y*y;
    }
};
int main()
{
	Solution s;
	vector<pair<int,int>> points{{0,0},{1,0},{2,0}};
	cout<<s.numberOfBoomerangs(points)<<endl;

}

