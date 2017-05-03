/*
给出一系列正整数，让它们依次做浮点数除法。
现可以在除法中添加括号，改变除法的顺序。求出使得最终结果最大的除法式子。
例如：[1000,100,10,2] ， 返回"1000/(100/10/2)"
*/
/*
思路：X1/X2/X3/../Xn可以写作 (X1/X2) * Y,无论括号加在哪儿，X1总是被除数，
X2总是除数。所以只需要使得Y最大，而Y最大为X3*...Xn。
所以结果总是X1/(X2/X3/.../Xn) =(X1*X3*..*Xn)/X2。
 */
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
	string optimalDivision(vector<int>& nums) {
        string ans;
        if(!nums.size()) return ans;
        ans = to_string(nums[0]);
        if(nums.size()==1) return ans;
        if(nums.size()==2) return ans + "/" + to_string(nums[1]);
        ans += "/(" + to_string(nums[1]);
        for(int i = 2; i < nums.size();++i)
            ans += "/" + to_string(nums[i]);
        ans += ")";
        return ans;
    }
};
int main()
{
	Solution s;
	vector<int> nums{1000,1000,10,2};
	cout << s.optimalDivision(nums) << endl;
}

