/*
给出一组数，计算它们的二进制距离和。
两个数的二进制距离，也就是二进制位不同的个数。
*/
/*
思路：1.直接调用两个数的二进制距离函数，然后两层循环遍历。超时。
	  2.由于两个数两个数的计算会是O(n^2)的时间，所以从其他方面考虑。
	  每个数都是32位，那么我们可以先计算其中某一位对总的二进制距离的贡献，然后都加起来。
	  可以这样计算是因为，两个数的二进制距离也是每一位每一位算出来的。
	  n歌数，针对32位中的某一位，如果有k个1，那么这一位对总距离的贡献就是k(n-k)。
	  (对总距离有贡献的只有1个位是1，1个位是0的情况)
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
        int totaldis = 0, n = nums.size(), bitcount, mask = 1;
        for(int i=0; i < 32; ++i)
        {
        	bitcount = 0;
        	for(int num:nums)
        	{
        		if(num & mask) ++bitcount;
        	}
        	totaldis += bitcount*(n-bitcount);
        	mask <<= 1;
        }
        return totaldis;
    }
};
int main()
{
	Solution s;
	vector<int>  nums{3, 10, 5, 25, 2, 8};
	cout << s.totalHammingDistance(nums) <<endl;
}

