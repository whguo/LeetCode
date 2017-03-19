/*
A,B,C,D四个数组，求有多少种组合(i, j, k, l)，使得A[i] + B[j] + C[k] + D[l]=0。
四个数组长度相同，0到500之间，所有数字在-2^28到2^28-1之间，这样和不会超出int界限。
*/
/*
思路：分别用map记录A和B，C和D中数的和，然后用一个map中的数在另一个map中找相反数。
 */
#include <iostream>
#include <vector> 
#include <unordered_map>
using namespace std;


class Solution {
public:
	void fillMap(vector<int>& A, vector<int>& B, unordered_map<int,int> &m)
    {
        int n = A.size();
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
          ++m[A[i] + B[j]];
          
    }
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int>	map1,map2;
        fillMap(A,B,map1);
        fillMap(C,D,map2);
        int result = 0;
        for(auto it=map1.begin(); it != map1.end(); ++it)
        {
        	if(map2.count(-it->first)!=0)
        		result += it->second*map2[-it->first];
        }
        return result;
    }
};
int main()
{
	Solution s;
	vector<int> nums1{0,1,1,0,0,1};
	vector<int> nums2{-1,1,1,0,-1,1};
	vector<int> nums3{2,1,1,-1,-2,1};
	vector<int> nums4{0,-3,1,0,3,1};
 	cout<<s.fourSumCount(nums1,nums2,nums3,nums4)<<endl;
}

