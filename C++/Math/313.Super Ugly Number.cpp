/*
Super Ugly Number：正整数，它的所有质因数都在给定的质数列表里。
求第n个Super Ugly Number。
eg：primes = [2, 7, 13, 19]
[1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]是前12个super ugly number。
*/
/*
思路：使用优先级队列，该队列中调用最小堆。
或者直接循环找，类似Ugly Number。
*/
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct cmp
{
	bool operator()(int a, int b) {
		return a > b;
	}
};

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
        ugly[0]=1;
        for(int i=1; i<n; i++){
            for(int j=0; j<primes.size(); j++) ugly[i]=min(ugly[i],ugly[index[j]]*primes[j]);
            for(int j=0; j<primes.size(); j++) index[j]+=(ugly[i]==ugly[index[j]]*primes[j]);
        }
        return ugly[n-1];

		/*用小堆，但是更慢。
		vector<int> count(primes.size(), 0);
		unordered_multimap<int, int>	mymap;
		priority_queue<int, vector<int>, cmp> myqueue;
		vector<int> result(n);
		result[0] = 1;
		for (int i = 0; i < primes.size(); ++i)
		{
			mymap.emplace(primes[i], i);
			myqueue.push(primes[i]);
		}
		for (int i = 1, tmp; i < n; ++i)
		{
			tmp = myqueue.top();
			result[i] = tmp;
			if (tmp == result[i - 1])	--i;
			myqueue.pop();
			unordered_map<int, int>::iterator it = mymap.find(tmp);
			count[it->second]++;
			tmp = result[count[it->second]] * primes[it->second];
			myqueue.push(tmp);
			mymap.emplace(tmp, it->second);
			mymap.erase(it);
		}
		return result[n - 1];*/
	}
};
int main()
{
	Solution s;
	vector<int> primes{ 2, 7, 13, 19 };
	cout << s.nthSuperUglyNumber(10, primes) << endl;
}

