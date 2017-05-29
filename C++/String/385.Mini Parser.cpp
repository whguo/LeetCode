/*
给定一个字符串，非空，不包含空格，只有数字0-9,[,],-和,，要求把它解析成NestedInteger 类型。
NestedInteger 类型要么是一个数字，要么是一个数字加一个list。
例如：给出s = "324"，返回一个NestedInteger对象，包含一个整数324。
给出s = "[123,[456,[789]]]，返回一个NestedInteger对象，包含整数123，和一个vector<NestedInteger>。
*/
/*
思路：有递归的思想
 */
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution {
public:
	NestedInteger deserialize(string s) {
        istringstream in(s);
        return deserialize(in);
        
    }
    NestedInteger deserialize(istringstream &in) {
    	int number;
        if(in>>number)	return NestedInteger(number); //如果开头是数字，那么一定是单个数的
        in.clear();
        in.get();
        NestedInteger list;
        while(in.peek() != ']')
        {
        	list.add(deserialize(in));
        	if(in.peek()==',')
        		in.get();
        }
        in.get();
        return list;
    }
};

int main()
{
	Solution s;
}

