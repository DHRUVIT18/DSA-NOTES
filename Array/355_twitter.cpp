class Twitter {
public:
    unordered_map<int,unordered_set<int>>user;
    vector<pair<int,int>>tweets;
    Twitter() {
       user.clear();
        tweets.clear();
    }
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
      vector<int>feeds;
        int count=0;
        for(int i=tweets.size()-1;i>=0;i--){
            auto it=tweets[i];
            if(count>9){
                break;
            }
            if(user[userId].find(it.first)!=user[userId].end() or it.first==userId){
                feeds.push_back(it.second);
                count++;
            }
        }
        return feeds;
        
    }
    
    void follow(int followerId, int followeeId) {
        user[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */