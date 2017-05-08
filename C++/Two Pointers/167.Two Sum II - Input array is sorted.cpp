/*
有序数组，返回两个数的index，这两个数的和为给定的数。
下标小的在前。
*/
/*
思路：头尾两个指针，和大于给定数后边的往前挪，小于给定数前边的往后挪。
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int high = numbers.size()-1,low = 0;
        while(numbers[low]+numbers[high]!=target)
        {
        	if(numbers[low]+numbers[high]<target) 	++low;
        	else	--high;
        }
        return vector<int>({low+1,high+1});
    }
};

int main()
{
	Solution s;
	vector<int> nums,out{1,2,3,4,5,6,7};
	out = s.twoSum(nums,10);
	for(int i = 0; i < out.size(); ++i)
	{
		cout<<out[i]<<endl;
	}
}