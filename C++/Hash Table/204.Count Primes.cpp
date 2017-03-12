/*
求小于给定数的素数个数。
*/
/*
思路：埃氏筛法。
一直筛到根号n为止即可。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
	int countPrimes(int n) {
        int count = 0, start=2;
        vector<bool>	isPrime(n+1,true);
        isPrime[0] = false, isPrime[1] = false;
        while(start<=sqrt(n))
        {
        	isPrime[start]=true;
        	for(int i=start*start; i <= n; i += start)
        	{
        		isPrime[i] = false;
        	}
        	while(!isPrime[start])	++start;
        }
        for(int i=2; i <= n; ++i)
        {
        	if(isPrime[i])	++count;
        }
        return count;
    }
};

int main()
{
	Solution s;
	cout<<s.countPrimes(100)<<endl;
}

