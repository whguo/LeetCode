/*
打印杨辉三角。
*/

#include <iostream>
#include <vector>
#include <windows.h>
#include <windef.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows<=0)	return result;
        vector<int> temp{1};
        for(int i=0; i < numRows; ++i)
        {
        	result.push_back(temp);
        	vector<int> tmp{1};
        	for(int j=0; j < temp.size()-1; ++j)
        	{
        		tmp.push_back(temp[j]+temp[j+1]);
        	}
        	tmp.push_back(1);
        	temp = tmp;
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<vector<int>> nums;
	nums = s.generate(5);
	for(int i=0 ; i < nums.size(); ++i)
	{
		for(int j=0; j < nums[i].size(); ++j)
		{
			cout<<nums[i][j];
		}
		cout<<endl;
	}
}