/*
数组中有两个数出现了一次，其他数出现了两次。找出这两个数。
*/
/*
思路：先遍历一次数组，求出所有数的异或，也就是这两个数的异或diff。
然后diff与它的相反数求与运算，得到diff最后一位二进制位是1的位置。
这个位置是1，说明两个数中有且只有一个，该位为1。不会是两个数的该位都为1。
所以可以根据这一位将所有的数分成两个部分，一个是该位为1的，一个是不为1的。
遍历数组第二次，该位为1的与或，该位不为1的与或，两个与或的结果就是这两个数(因为别的数都出现两次)。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
		for (int n:nums)
		{
			diff ^= n;
		}
		diff &= -diff; 		//获取最右边的二进制位是1的数。
		vector<int> result{0,0};
		for (int num : nums)
		{
			if ((num & diff) == 0)
				result[0] ^= num;
			else
				result[1] ^= num;
		}
		return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,2,1,3,2,5};
	vector<int> out = s.singleNumber(nums);
	cout<<out[0]<<" "<<out[1]<<endl;
}

