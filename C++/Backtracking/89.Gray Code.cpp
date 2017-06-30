/*
格雷码，给出位数n，按顺序返回格雷码。
顺序为，二进制位每次变更一位。
*/
/*
思路：第k个格雷码的求法位k ^(k/2)。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int>	result;
        for(int i=0; i < 1<<n; ++i)
        {
        	result.push_back(i ^ i>>1);
        }
        return result;
    }
};
int main()
{
	Solution s;
    vector<int> out = s.grayCode(3);
    for(int n:out)
    	cout<<n<<endl;
}

