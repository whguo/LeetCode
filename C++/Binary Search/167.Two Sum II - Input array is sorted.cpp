/*
有序数组，返回两个数的index，这两个数的和为给定的数。
下标小的在前。
*/
/*
思路：二分法的效率不如前后两个指针。
*/
#include <iostream>
#include <vector>
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
	vector<int> nums{2, 7, 11, 15},out;
	out = s.twoSum(nums,9);
	for(int n:out)
		cout<<n<<" ";
	cout<<endl;
}

