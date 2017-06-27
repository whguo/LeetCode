/*
给出正整数n，问有n个结点的二叉搜索树有多少种?
例如：给出3，返回5。
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
/*
思路：设G(n)为最终要求的结果，n个结点二叉树个数。
	  设F(i,n)为当i为二叉树根结点时的n个结点的二叉树个数。
	  由定义可知，G(n)=F(1,n)+F(2,n)+..+F(n,n)。也就是分别把每个数当做根结点的总和。
	  G(0) = 1， G(1) = 1.
	  此时，我们分析当i为根结点时，左侧有i-1个结点，右侧有n-i个结点。当根结点为i时的二叉树个数
	  就是左侧i-1个结点能构成的个数，乘上右侧的。也就是F(i,n) = G(i-1)*G(n-i)。
	  所以最终的式子为G(n) = G(0)*G(n-1)+G(1)*G(n-2)+..+G(n-1)G(0)。
	  也就是G(n)依赖于G(0)...G(n-1)的值。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
        vector<int> G(n+1);
        G[0] = G[1] = 1;
        for(int i=2; i <= n; ++i)
        {
        	for(int j=1; j <=i; ++j)
        		G[i] += G[j-1] * G[i-j];
        }
        return G[n];
    }
};
int main()
{
	Solution s;
	cout << s.numTrees() <<endl;
}

