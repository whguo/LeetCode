/*
判断一个数独是否是合法的。
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<string>& board) {
		vector<unordered_map<char, int>>	row(9);
		vector<unordered_map<char, int>>	col(9);
		vector<unordered_map<char, int>>	square(9);
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] == '.')	continue;
				if (row[i].find(board[i][j]) == row[i].end())
					row[i].insert({ board[i][j], 1 });
				else
					return false;

				if (col[j].find(board[i][j]) == col[j].end())
					col[j].insert({ board[i][j], 1 });
				else
					return false;

				if (square[i / 3 * 3 + j / 3].find(board[i][j]) == square[i / 3 * 3 + j / 3].end())
					square[i / 3*3 + j / 3].insert({ board[i][j], 1 });
				else
					return false;
			}
		}
		return true;
	}

};

int main()
{
	Solution s;
	vector<string> board{ { ".87654321" }, { "2........" }, { "3........" }, { "4........" }, { "5........" }, { "6........" }, { "7........" }, { "8........" }, { "9........" } };
	cout << s.isValidSudoku(board) << endl;
}

