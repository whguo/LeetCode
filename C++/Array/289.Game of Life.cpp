/*
#二维矩阵中，每个数有0(死亡)和1(存活)两个状态，它们的下一个状态由8领域中其他数的存活状态决定：
#一个存活的点，邻居中存活的个数小于2，它下一个状态死亡
#一个存活的点，邻居中存活的个数是2或3，它下一个状态存活
#一个存活的点，邻居中存活的个数大于3，它下一个状态死亡
#一个死亡的点，邻居中存活的个数等于3，它下一个状态复活
求下一个状态的矩阵
*/
/*
思路：考虑用一个Int类型存储当前状态和之后状态两个值，所以采用位运算。
考虑到为了方便提取出后一个状态，可以用最右边一位表示当前状态，左边一位表示下一个状态，
只需右移一次即可得到下一状态。
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int count = 0;
				for (int p = max(i - 1, 0); p < min(i + 2, m); ++p)
					for (int q = max(j - 1, 0); q < min(j + 2, n); ++q)
						count += board[p][q]&1;
				if (count == 3 || count - board[i][j] == 3)
					board[i][j] |= 2;
			}
		}
		for (int i = 0; i<m; ++i)
			for (int j = 0; j<n; ++j)
				board[i][j] >>= 1;
    }
};

int main()
{
	Solution s;
	vector<vector<int>> nums(4,vector<int>(4));
	nums[0][0] = 1;
	nums[0][1] = 0;
	nums[0][2] = 0;
	nums[0][3] = 1;
	nums[1][0] = 0;
	nums[1][1] = 1;
	nums[1][2] = 1;
	nums[1][3] = 0;
	nums[2][0] = 1;
	nums[2][1] = 0;
	nums[2][2] = 1;
	nums[2][3] = 0;
	nums[3][0] = 0;
	nums[3][1] = 0;
	nums[3][2] = 1;
	nums[3][3] = 1;
	s.gameOfLife(nums);
	for(int i=0 ; i < 4; ++i)
	{
		for(int j=0; j < 4; ++j)
		{
			cout<<nums[i][j]<<endl;
		}
	}
	
}