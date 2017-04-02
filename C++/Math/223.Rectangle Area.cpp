/*
求两个矩形所占总面积。
*/

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A,E), right = max(min(C,G), left);
        int bottom = max(B,F), top = max(min(D,H), bottom);
        return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
    }
};
int main()
{
	Solution s;
	cout<<s.computeArea(-3,0,3,4,0,-1,9,2)<<endl;
}

