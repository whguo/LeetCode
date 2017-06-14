/*
给出数组，其中只有一个元素出现一次，其他的出现三次。找出出现一次的数。
*/
/*
思路：1.统计每个元素出现的次数。
2.不管非单个元素重复多少次，这是通用做法。
  对于右数第i位，如果单个元素该位为0，则该位为1的元素总数为3的整数倍。
  如果单个元素该位为1，则该位为1的元素总数不为3的整数倍（也就是余1）。
  换句话说，如果第i位为1的元素总数不为3的整数倍，则单个数的第i位为1，否则为0.
  （如果非单个元素重复n次，则判断是否为n的整数倍）
3.2做法需要对每个数字各位都访问一次，还是过于冗杂了。
  1)%3运算只有三种状态：00,01,10，因此我们可以使用两个位来表示当前位%3。
  2)对于每一位，我们让Two，One表示当前位的状态，B表示输入数字的对应位，Two+和One+表示输出状态。
  可以得到如下真值表:
  Two One B Two+ One+
	0  0  0   0   0
	0  0  1   0   1
	0  1  0   0   1
	0  1  1   1   0
	1  0  0   1   0
	1  0  1   0   0
   经过化简后，可以得到如下表达式:
	One+ = (One ^ B) & (~Two)
	Two+ = (~One+) & (Two ^ B)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		/*方法2
        int ret = 0,mask = 1;
        while(mask)
        {
            int countOne = 0;
            for(int i = 0; i < nums.size(); i ++)
            {
                if(nums[i] & mask)	countOne ++;
            }
            if(countOne % 3 == 1)	ret |= mask;
            mask <<= 1;
        }
        return ret;*/
        int ones = 0, twos = 0;
    	for(int i = 0; i < nums.size(); ++i)
    	{
        	ones = (ones ^ nums[i]) & ~twos;
        	twos = (twos ^ nums[i]) & ~ones;
    	}
    	return ones;
    }
};

int main()
{
	Solution s;	
	vector<int> nums{3,1,3,3,2,1,4,1,4,4};
	cout << s.subsets(nums) <<endl;
}

