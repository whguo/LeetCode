/*
在二维字母矩阵中寻找给定的字母串，两个字母相邻即可(上下左右)。
*/
/*
思路：DFS递归。每次把之前遍历过的位置改为' '字符，防止再次遍历，递归过后再改回来。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0 ; i < board.size(); ++i)
        {
        	for(int j=0 ; j < board[i].size(); ++j)
        	{
        		if(board[i][j]==word[0])
        		{
        			board[i][j] = ' ';
        			if(helpExist(board,word,i,j,1)==true)	return true;
        			board[i][j] = word[0];
        		}	
        	}
        }
        return false;
    }
    bool helpExist(vector<vector<char>>& board,const string& word,int row,int col,int index)
    {
    	if(index==word.size())	return true;
    	if(row>0 && board[row-1][col]==word[index])
    	{
    		board[row-1][col] = ' ';
    		if(helpExist(board,word,row-1,col,index+1)==true)	return true;
    		board[row-1][col] = word[index];
    	}
    	if(col>0 && board[row][col-1]==word[index])
    	{
    		board[row][col-1] = ' ';
    		if(helpExist(board,word,row,col-1,index+1)==true)	return true;
    		board[row][col-1] = word[index];
    	}
    	if(row<board.size()-1 && board[row+1][col]==word[index])
    	{
    		board[row+1][col] = ' ';
    		if(helpExist(board,word,row+1,col,index+1)==true)	return true;
    		board[row+1][col] = word[index];
    	}
    	if(col<board[0].size()-1 && board[row][col+1]==word[index])
    	{
    		board[row][col+1] = ' ';
    		if(helpExist(board,word,row,col+1,index+1)==true)	return true;
    		board[row][col+1] = word[index];
    	}
    	return false;
    }
};
int main()
{
	Solution s;
	vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << s.exist(board,"ABCB");
}

