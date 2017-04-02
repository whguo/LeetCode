/*
数组代表一个非负整数，求该数加1的结果。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
        int flag = 1, sum=0;
        for(int i=digits.size()-1; i >=0; --i)
        {
        	sum = digits[i] + flag;
        	digits[i] = sum % 10;
        	flag = sum/10;
        }
        if(flag)	digits.insert(digits.begin(),1);
        return digits;
    }
};
int main()
{
	Solution s;
	vector<int> out{9,9,9};
	out = s.plusOne(out);
	for(int i:out)
		cout<<i<<" ";
	cout<<endl;
}

