/*
设计一个简易的推特。
*/

#include <iostream>
#include <vector> 
#include <unordered_map>
#include <unordered_set> 
using namespace std;
class RandomizedSet {
public:
	//vector<int>	myset;
	unordered_map<int,int>	mymap;
	int count;
    /** Initialize your data structure here. */
    RandomizedSet() {
        count = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mymap.count(val)==0)
        {
        	mymap[val] = 1;
        	count++;
        	return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mymap.count(val)!=0)
        {
        	mymap.erase(val);
        	--count;
        	return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand()%count;
        auto it = mymap.begin();
        advance(it,r);
        return it->first;
    }
};

int main()
{
	RandomizedSet obj = new RandomizedSet();
 	bool param_1 = obj.insert(val);
 	bool param_2 = obj.remove(val);
 	int param_3 = obj.getRandom();
}

