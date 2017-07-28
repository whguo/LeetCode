/*
给出一个二维数组，需要很多次调用函数sumRegion(r1,c1,r2,c2)，
返回所代表的左上右下区域所有数的和。
*/
/*
思路：用一个二维数组，记录从最左上到当前下标区域所有数的和。
 */
#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
	int row, col;
    vector<vector<int>> sums;
	NumMatrix(vector<vector<int>> matrix) {
        row = matrix.size();
        col = row>0 ? matrix[0].size() : 0;
        sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                sums[i][j] = matrix[i-1][j-1] + 
                             sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
};
int main()
{
	vector<vector<int>> matrix{{3, 0, 1, 4, 2},{5, 6, 3, 2, 1},{1, 2, 0, 1, 5},
								{4, 1, 0, 1, 7},{1, 0, 3, 0, 5}};
	NumMatrix* obj = new NumMatrix(matrix);
    cout<<obj->sumRegion(2,1,4,3)<<endl;
}

