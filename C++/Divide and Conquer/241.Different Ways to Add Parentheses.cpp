/*
给出计算式，包含计算数以及+,-,*三种计算符。
可以在计算式任何位置添加括号，返回所有可能的计算结果。
*/
/*
思路：把输入的算式根据每个计算符分为两部分，然后递归解决
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        int size = input.size();
        for (int i = 0; i < size; i++) 
        {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') 
            {
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i+1));
                for (auto n1 : result1) 
                {
                    for (auto n2 : result2) 
                    {
                        if (cur == '+')	result.push_back(n1 + n2);
                        else if (cur == '-')	result.push_back(n1 - n2);
                        else	result.push_back(n1 * n2);    
                    }
                }
            }
        }
        //如果输入只有一个数，没有操作符
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        return result;
    }
};

int main()
{
	Solution s;	
	vector<int> nums = s.diffWaysToCompute("2*3-4*5");
	for(int n:nums)
		cout<<n<<" ";
	cout<<endl;
}

