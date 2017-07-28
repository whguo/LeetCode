/*
给出一个数组，需要很多次调用函数sumRange(x,y)，返回下标在x和y之间所有数的和。
*/
/*
思路：增加一个数组，记录从开始到当前下标之前所有数的和。
 */
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
	vector<int> cursum;
    NumArray(vector<int>& nums) {
        cursum.resize(nums.size()+1);
        cursum[0] = 0;
        for(int i=0; i < nums.size(); ++i)
        	cursum[i+1] = cursum[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return cursum[j+1]-cursum[i];
    }
};
int main()
{
	vector<int> nums{-2, 0, 3, -5, 2, -1};
	NumArray* obj = new NumArray(nums);
    cout<<obj->sumRange(0,2)<<endl;
    cout<<obj->sumRange(2,5)<<endl;
    cout<<obj->sumRange(0,5)<<endl;
}

