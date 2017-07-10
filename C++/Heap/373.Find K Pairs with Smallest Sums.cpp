/*
给出两个有序数组和数k，从两个数组中各拿一个组成数对，
问和最小的k个数对是哪些?
 */
/*
思路：使用一个indice数组，indice[i]表示当前状态下，
	  nums1数组中的第i个数已经加入结果中的pair个数。
	  每次循环加入一个pair，对应的下标加1。
	  在寻找每一个和最小的pair过程中，对nums1中每个数nums1[i]循环，
	  配对的pair分别就是nums2[indice[i]]。
 */
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        int m = nums1.size() , n = nums2.size();
        k = min(k, m * n);
        vector<int> indice(m, 0);
        while(k-- > 0)
        {
            int tmp_index = 0;
            long tmp_sum = LONG_MAX;
            for(int i = 0; i < m; i++)
            {
                if(indice[i] < n && tmp_sum >= nums1[i] + nums2[indice[i]])
                {
                    tmp_index = i;
                    tmp_sum = nums1[i] + nums2[indice[i]];
                }
            }
            res.push_back(make_pair(nums1[tmp_index], nums2[indice[tmp_index]]));
            indice[tmp_index]++;
        }
        return res;
    }
};
int main()
{
	Solution s;
	vector<int> nums1{1,7,11},nums2{2,4,6};
	vector<pair<int, int>> out =  s.kSmallestPairs(nums1,nums2,3);
	for(auto p:out)
		cout<<p.first<<" "<<p.second<<endl;
}

