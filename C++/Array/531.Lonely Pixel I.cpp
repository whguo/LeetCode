/*
二维char数组，B代表黑，W代表白。
求“孤独黑”个数，指该行和该列只有它一个黑。
*/
/*
思路：遍历一次，用两个数组记录哪行和哪列有单独的B。
然后比较一下相应的行和列能否对的上即可。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size(),result=0;
        vector<int> row(m,-1),col(n,-1);
        for(int i=0; i < m; ++i)
        {
        	for(int j=0; j < n; ++j)
        	{
        		if(picture[i][j]=='B')
        		{
        			row[i] = (row[i]==-1)? j:-2;
        			col[j] = (col[j]==-1)? i:-2;
        		}
        	}
        }
        for(int i=0; i < m; ++i)
        {
        	if(row[i]>=0 && col[row[i]]==i)	++result;
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<vector<char>>  picture{{'W', 'B', 'B'},{'W', 'B', 'W'},{'B', 'W', 'W'}};
	cout<<s.findLonelyPixel(picture)<<endl;
}

