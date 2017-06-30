/*
给出数组，可能有重复元素，返回没有重复的全排列。
*/
/*
思路：先排序，然后挨个换，但是不换回来，递归传参数使用传值不传引用。
	  不换回来，也就是说当前位置和start互换，那么下一次循环，下一个位置和start互换相当于
	  先换回来，然后start和下一个位置互换。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> result;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
        helpPermute(nums, 0);
        return result;
    }
    void helpPermute(vector<int> nums,int start)
    {
    	if (start == nums.size()-1) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (start != i && nums[start] == nums[i]) continue;
            swap(nums[start], nums[i]);
            helpPermute(nums, start+1);
        }
    }
};
int main()
{
	Solution s;
	vector<int>	nums{1,2,3,4};
    vector<vector<int>> out = s.permuteUnique(nums);
    for(auto vec:out)
    {
    	for(int n:vec)
    		cout<<n<<" ";
    	cout<<endl;
    }
}

