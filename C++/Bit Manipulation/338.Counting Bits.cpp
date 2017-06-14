/*
给出一个数num，返回从0-num所有数，每一个的二进制位中分别有几个1。
可否O(n)时间内做到?
*/
/*
思路：遍历一次，动态规划记录之前的结果。
	  如果n为2的次方，n中有dp[n] = 1;
	  如果n末尾为1，那么dp[n] = dp[n-1]+1;
	  如果n末尾为0，那么dp[n] = dp[n>>1]。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		/*
        vector<int> result(num+1);
        for(int i=1; i <= num; ++i)
        {
        	if((i &(i-1))==0)	result[i] = 1;
        	else if(i&1)	result[i] = result[i-1]+1;
        	else	result[i] = result[i>>1];
        }
        return result;*/
        
        //化简版本。
        //如果i是2的次方，i&(i-1)为0，结果为1。
        //如果i不是2的次方，那么i&(i-1)把最后一个二进制1去掉，结果一定比i小，是已经计算过的。
        vector<int> result(num+1);
        for(int i=1; i <= num; ++i)
        {
        	result[i] = result[i&(i-1)] + 1;
        }
        return result;    
    }
};
int main()
{
	Solution s;
	vector<int> out=s.countBits(18);
	for(int n:out)
		cout<<n<<" ";
	cout<<endl;
}

