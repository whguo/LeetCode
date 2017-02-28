/*
设计数据结构，支持插入、删除、比例操作，时间复杂度O(1)
*/
/*
考虑的时间复杂度是O(1)，所以肯定使用哈希表。
C++中的无序容器unordered_map内部就是哈希函数做的，所以使用这个。
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class RandomizedSet {
public:
	vector<int> nums;
	unordered_map<int, int> hash;
	/** Initialize your data structure here. */
	RandomizedSet(){}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (hash.find(val) != hash.end())
			return false;
		nums.push_back(val);
		hash.emplace(val, nums.size() - 1);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (hash.find(val) == hash.end())
			return false;
		int last = nums.back();
		hash[last] = hash[val];
		nums[hash[val]] = last;
		nums.pop_back();
		hash.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}
};

int main()
{
	srand(time(NULL));
	RandomizedSet obj;
	cout << obj.insert(1) << endl;
	cout << obj.insert(1) << endl;
	cout << obj.insert(2) << endl;
	cout << obj.remove(2) << endl;
	cout << obj.getRandom() << endl;
}