/*
返回一个数加一后的值(数可以任意大)。该数用一个数组表示，每个元素表示一位。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
        int length = digits.size(),temp;
        temp = digits[length-1]+1;
        int flag = temp/10 , i = length-2;
        digits[length-1]=temp%10;
        while(i>=0)
        {
        	temp = digits[i]+flag;
        	digits[i--] = temp%10;
        	flag = temp/10;
        }
        if(flag==1)		digits.insert(digits.begin(),1);
        return digits;
    }
};

int main()
{
	Solution s;;
	vector<int> nums{9,9,9,9};
	nums = s.plusOne(nums);
	for(int i=0 ; i < nums.size(); ++i)
	{
		cout<<nums[i]<<"\t";
	}
	cout<<endl;
}

