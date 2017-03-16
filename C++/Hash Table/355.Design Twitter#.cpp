/*
设计一个简易的推特。
*/

#include <iostream>
#include <vector> 
#include <unordered_map>
#include <unordered_set> 
#include <pair>
#include <heap>
using namespace std;
class Twitter {
    struct Tweet
	{
		int time;
		int id;
		Tweet(int ntime,int nid): time(ntime),id(nid){}
	};
public:
    unordered_map<int,vector<Tweet>>	tweets;
    unordered_map<int,unordered_set<int>>	follows;
    int time;
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(time++,tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<Tweet*,Tweet*>>   h;
        for(auto& u:follows[userId])
        {
        	auto& t = tweets[u];
        	if(t.size()>0)
        		h.emplace_back(t.data(),t.data()+t.size()-1);
        }
        auto& t = tweets[userId];//self
        if(t.size()>0)
        	h.emplace_back(t.data(),t.data()+t.size()-1);
        auto f = [](const pair<Tweet*,Tweet*>& x,const pair<Tweet*,Tweet*>& y)
        {
        	return x.second->time < y.second->time;
        };
        std::make_heap(h.begin(),h.end(),f);
        const int n = 10;
        vector<int>	result;
        result.reserve(n);
        for(int i=0; (i<n) && !h.empty(); ++i)
        {
        	std::pop_heap(h.begin(),h.end(),f);
        	auto& hb = h.back();
        	result.push_back(hb.second->id);
        	if(hb.first==hb.second--)
        		h.pop_back();
        	else
        		std::push_heap(h.begin(),h.end(),f);
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followeeId!=followerId)
        	follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

int main()
{
	Twitter obj = new Twitter();
 	obj.postTweet(1,5);
 	vector<int> param_2 = obj.getNewsFeed(1);
 	obj.follow(1,2);
 	obj.unfollow(2,1);
}

