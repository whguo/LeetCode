/*
计算表达式的值。计算符只有加减乘除。
*/
/*
思路：由于只涉及加减乘除，没有括号，因此可以不用栈。
使用istringstream，在前后加一个'+'。
每次循环从stream中取出一个char，如果是加或者减，那么在结果中加上前一个数。
并且从stream中取出一个整数，而且用之前取出的char标记该数的正负符号。
如果取出的char是乘除，那么再取出一个整数与前一个数做乘除，结果赋予前一个数。
 */
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

class Solution {
public:
	int calculate(string s) {
        istringstream in('+' + s + '+');
        int total = 0, term = 0, n;
        char op;
        while (in >> op) {
            if (op == '+' or op == '-') 
            {
                total += term;
                in >> term;
                term *= 44 - op;//(+的ASCII码为43，-的是45)
            } 
            else
            {
                in >> n;
                if (op == '*')
                    term *= n;
                else
                    term /= n;
            }
        }
        return total;
    }
};

int main()
{
	Solution s;;
	cout<<s.calculate("3+2*2-5 / 2")<<endl;
}

