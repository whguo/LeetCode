#设计一个简单的Twitter，功能如下：
#发推
#获取目标用户的最新的10条推特（返回的推特包括自己发的推特和关注人的推特）
#关注
#未关注
import collections
class Twitter(object):
    def __init__(self):
        self.tweets_count = 0
        self.follower = collections.defaultdict(set)
        self.tweet = collections.defaultdict(list)

    def postTweet(self, userId, tweetId):
        self.tweet[userId].append([tweetId,self.tweets_count])
        self.tweets_count += 1

    def getNewsFeed(self, userId):
        recent_tweets = []
        user_list = list(self.follower[userId])+[userId]#所有关注者和自己
        userId_tweet_index = [[userid,len(self.tweet[userid])-1] for userid in user_list if userid in self.tweet]

        for _ in range(10):
            max_index = max_tweet_id = max_user_id = -1
            for i, (user_id, tweet_index) in enumerate(userId_tweet_index):
                if tweet_index >= 0:
                    tweet_info = self.tweet[user_id][tweet_index]
                    if tweet_info[1] > max_tweet_id:
                        max_index, max_tweet_id, max_user_id = i, tweet_info[1], user_id

            if max_index < 0: break
            recent_tweets.append(self.tweet[max_user_id][userId_tweet_index[max_index][1]][0])
            userId_tweet_index[max_index][1] -= 1

        return recent_tweets

    def follow(self, followerId, followeeId):
        if followerId!=followeeId:
            self.follower[followerId].add(followeeId)

    def unfollow(self, followerId, followeeId):
        if followerId in self.follower and followeeId in self.follower[followerId]:
            self.follower[followerId].remove(followeeId)

obj = Twitter()
obj.postTweet(1,5)
print(obj.getNewsFeed(1))
obj.follow(1,2)
obj.postTweet(2,6)
obj.unfollow(1,2)
print(obj.getNewsFeed(2))

