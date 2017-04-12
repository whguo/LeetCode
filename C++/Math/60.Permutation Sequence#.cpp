/*
寻找n个数的全排列中第k大的数。
*/
/*
思路：DFS超时。
比如当前长度是n，我们知道每个相同的起始元素对应(n-1)!个permutation，
也就是(n-1)!个permutation后会换一个起始元素。
因此，只要当前的k进行(n-1)!取余，得到的数字就是当前剩余数组的index，
如此就可以得到对应的元素。如此递推直到数组中没有元素结束。
 */

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
        int i,j,f=1;
        // s的左侧表示形成的部分序列，右侧表示剩余的数
        string s(n,'0');
        for(i=1; i <= n; ++i)
        {
            f *= i;  //f此时是n的阶乘
            s[i-1] += i; // s 是 1234...n
        }
        for(i=0,k--;i < n; ++i)
        {
            f /= n-i;
            j = i+k/f; // 计算应该放在s[i]位置的数
            char c = s[j];
            // i和j之间的数向前移
            for(;j>i;j--)
                s[j]=s[j-1];
            k %= f; //计算剩余的k
            s[i] = c;
        }
        return s;
    }
};
int main()
{
	Solution s;
	cout<<s.plusOne(4,5)<<endl;
}

