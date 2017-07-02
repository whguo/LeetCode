/*
一个二叉树可以用它的前序遍历做序列化，用'#'表示空结点。
      9_
    /   \
   3     2
  / \   / \        ==>  序列化为 "9,3,4,#,#,1,#,#,2,#,6,#,#"
 4   1  #  6
/ \ / \   / \      
# # # #   # #
那么，给出一个序列，判断它是否是一个二叉树的前序序列。
*/
/*
思路：碰到'#',如果栈顶也是'#'，那么是连续两个，说明到叶结点，然后将栈顶'#'出栈，数字出栈。
	  再压入一个'#'，表示该结点遍历过了，用空代替。
 */
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char>	mystack;
        for(int i=0; i < preorder.length(); ++i)
        {
        	if(preorder[i] == '#')
        	{
        		if(!mystack.empty() && mystack.top()=='#')
        		{
        			mystack.pop();
        			if(mystack.empty())	return false;
        			else 	mystack.pop();
        			//这里是精髓。本来是要再压入一个'#'，但是如果栈顶此时仍然是一个'#'，那么就
        			//无法判断连续两个'#'，进行出栈操作。所以让下标减1，然后循环末尾再+1，使得
        			//下标保持不变，仍然指向一个'#'。如果栈顶是'#'，可以继续出栈，不是可以压栈。
        			--i;
        			continue;
        		}
        		mystack.push('#');
        	}
        	else if(preorder[i] != ',')
        	{
        		while(preorder[i]>='0' && preorder[i]<='9')	++i;
        		mystack.push('0');
        	}
        }
        //返回结果不能返回mystack.empty();
        //因为循环结束后正常会多压入一个'#'，表示所有结点已经遍历过，只剩一个空。
        return mystack.size()==1 && mystack.top()=='#';
    }
};
int main()
{
	Solution s;
	cout<< s.isValidSerialization("9,13,24,#,#,1,#,#,2,#,6,#,#");
}

