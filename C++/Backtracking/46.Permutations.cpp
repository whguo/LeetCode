/*
给出数组，没有重复元素，返回全排列。
*/
/*
思路：依次从start后面拿一个与start交换。递归start+1。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> result;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        helpPermute(nums,0);
        return result;
    }
    void helpPermute(vector<int>& nums,int start)
    {
    	if (start == nums.size()-1)    
        {
            result.push_back(nums);
            return;
        }
        for(int i=start; i < nums.size(); ++i)
        {
            int tmp;
            tmp = nums[i],nums[i] = nums[start], nums[start] = tmp; 
            helpPermute(nums,start + 1);
            tmp = nums[i],nums[i] = nums[start], nums[start] = tmp;
        }
    }
};
int main()
{
	Solution s;
	vector<int>	nums{3,2,1};
    vector<vector<int>> out = s.permute(nums);
    for(auto vec:out)
    {
    	for(int n:vec)
    		cout<<n<<" ";
    	cout<<endl;
    }
}

