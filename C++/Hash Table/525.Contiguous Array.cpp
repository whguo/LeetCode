/*
求最长子数组，使得0的个数和1的个数相等。
*/
/*
思路：记录下从头开始到每个位置，0个数和1个数的差，差相同的时候就是二者之间0和1个数相等的时候。
 */
#include <iostream>
#include <vector> 
#include <unordered_map>
#include <windows.h>
#include <windef.h>
using namespace std;


class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		unordered_map<int,int>	mymap;
		mymap[0] = -1;
		int zero=0, one=0, maxlen=0;
		for(int i=0; i < nums.size(); ++i)
		{
			if(nums[i]==0)	++zero;
			else	++one;

			if(mymap.count(zero-one)!=0)
				maxlen = max(maxlen,i-mymap[zero-one]);
			else
				mymap[zero-one] = i;
		}
		return maxlen;
    }
};
int main()
{
	Solution s;
	vector<int> nums{0,1,1,0,0,1};
 	cout<<s.findMaxLength(nums)<<endl;
}

