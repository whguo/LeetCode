/*
找出数组中最频繁出现的k个数
*/
/*
思路：使用优先级队列，或者桶排序。
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue> 
#include <utility>
using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int>		result;
        unordered_map<int,int>	mymap;
        priority_queue<pair<int,int>>		myqueue;
        for(int n:nums)
        	mymap[n]++;
        for(auto it=mymap.begin(); it != mymap.end(); ++it)
        {
        	myqueue.push(make_pair(it->second,it->first));
        	if(myqueue.size()>mymap.size()-k)
        	{
        		result.push_back(myqueue.top().second);
        		myqueue.pop();//优先级队列从头部出
        	}
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums{1,1,1,2,2,3};
	nums = s.topKFrequent(nums,2);
	for (int i = 0; i < nums.size(); ++i)
	{
		cout<<nums[i]<<endl;
	}
}

