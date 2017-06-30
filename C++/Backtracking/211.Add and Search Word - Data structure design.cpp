/*
设计数据结构，能够插入和查找字符串。
支持'.'通配符，代表任意一个字符。（所有单词均为小写字母）
*/
/*
思路：因为只有小写字母，可以考虑使用字典树，每个结点26个分叉。
      构造字典树时发现，需要一个结束标志，否则加入字符串"at","an"时搜索"a"结果为true。
      所以再加一个分叉，表示结束，一共27个分叉。
      每次插入字符串时在最后一个字母结点后加一个27分叉。
	  查找时，遇到字母判断分叉是否存在，存在则循环到下一个字母。
	  碰到'.'时，针对每个不是空的分叉进行递归。
	  循环结束时，一定要返回第27分叉是不是空，不能直接返回true。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Dictionary
{
	Dictionary* next[27];
	Dictionary(){for(int i=0; i<27; ++i) next[i]=NULL;}	
};
class WordDictionary {
public:
	Dictionary* root  =NULL;
    WordDictionary() {
        root = new Dictionary();
    }
    
    void addWord(string word) {
    	Dictionary* cur = root;
        for(char c:word)
        {
        	int index = c-'a';
        	if(cur->next[index]==NULL)
        		cur->next[index] = new Dictionary();		
        	cur = cur->next[index];
        }
        cur->next[26] = new Dictionary();
    }
    
    bool search(string word) {
        return helpSearch(root,0,word);
    }
    bool helpSearch(Dictionary* cur,int start,string& word)
    {
        for(int i=start; i < word.length(); ++i)
        {
        	if(word[i]=='.')
        	{
        		for(int j=0; j < 26; ++j)
        			if(cur->next[j] && helpSearch(cur->next[j],i+1,word))		return true;
        		return false;
        	}
        	else
        	{
        		int index = word[i]-'a';
        		if(cur->next[index]!=NULL)	cur = cur->next[index];
        		else return false;
        	}
        }
        return cur->next[26];
    }
};
int main()
{
	WordDictionary obj;
    obj.addWord("bad");
    obj.addWord("dad");
    obj.addWord("mad");
    cout<<obj.search("pad")<<endl;
    cout<<obj.search("bad")<<endl;
    cout<<obj.search(".ad")<<endl;
    cout<<obj.search("b..")<<endl;
    cout<<endl;
    obj.addWord("at");
    obj.addWord("and");
    obj.addWord("an");
    cout<<obj.search("a")<<endl;
}

