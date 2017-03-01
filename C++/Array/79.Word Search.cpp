/*
在二维字母矩阵中寻找给定的字母串，两个字母相邻即可(上下左右)
*/
/*
思路：DFS即可。
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
	vector<vector<char>> myboard;
	string myword;
public:
	bool exist(vector<vector<char>>& board, string word) {
		myboard = board , myword = word;
        for(int i=0 ; i < myboard.size(); ++i)
        {
        	for(int j=0 ; j < myboard[i].size(); ++j)
        	{
        		if(myboard[i][j]==myword[0])
        		{
        			myboard[i][j] = ' ';
        			if(dfs(i,j,1)==true)	return true;
        			myboard[i][j] = myword[0];
        		}
        	}
        }
        return false;
    }
    bool dfs(int i,int j,int index)
    {
    	if(index==myword.size())	return true;
    	if(i>0 && myboard[i-1][j]==myword[index])
    	{
    		myboard[i-1][j] = ' ';
    		if(dfs(i-1,j,index+1)==true)	return true;
    		myboard[i-1][j] = myword[index];
    	}
    	if(j>0 && myboard[i][j-1]==myword[index])
    	{
    		myboard[i][j-1] = ' ';
    		if(dfs(i,j-1,index+1)==true)	return true;
    		myboard[i][j-1] = myword[index];
    	}
    	if(i<myboard.size()-1 && myboard[i+1][j]==myword[index])
    	{
    		myboard[i+1][j] = ' ';
    		if(dfs(i+1,j,index+1)==true)	return true;
    		myboard[i+1][j] = myword[index];
    	}
    	if(j<myboard[0].size()-1 && myboard[i][j+1]==myword[index])
    	{
    		myboard[i][j+1] = ' ';
    		if(dfs(i,j+1,index+1)==true)	return true;
    		myboard[i][j+1] = myword[index];
    	}
    	return false;
    }
};

int main()
{
	Solution s;;
	vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	cout<<s.exist(board,"ABCB")<<endl;
}

