/*
打印杨辉三角的第n行。
*/
#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> result(rowIndex + 1);
		result[0] = 1;
		if (rowIndex == 0)	return result;
		for (int i = 1; i <= rowIndex; ++i)
		{
			//每一行都从后往前，避免被覆盖
			for (int j = i-1; j > 0; --j)
			{
				result[j] = result[j] + result[j-1];
			}
			result[i] = 1;
		}
		return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums = s.getRow(1);
	for(int i=0 ; i < nums.size(); ++i)
	{
		cout<<nums[i];
	}
}