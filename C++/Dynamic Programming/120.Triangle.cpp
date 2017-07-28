/*
给出三角形，找出一条从上到下的路径，使得和最小。
*/
/*
思路：从下到上。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-2; i >=0 ; --i)
        {
        	for(int j=0; j <= i; ++j)
        	{
        		triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
        	}
        }
        return triangle[0][0];
    }
};
int main()
{
	Solution s;
	vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
	cout<<s.minimumTotal(triangle)<<endl;
}

