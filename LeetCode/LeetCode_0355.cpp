class Twitter {
public:
    vector<pair<int, int> > V;
    map<int, set<int> > S;
    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        V.push_back(make_pair(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> tmp;
        for(int i = V.size() - 1; i >= 0; i--){
            if(ok(userId, V[i].first)){
                tmp.push_back(V[i].second);
            }
            if(tmp.size() == 10) break;
        }
        return tmp;
    }
    bool ok(int i, int j){
        if(i == j) return 1;
        if(S[i].find(j) != S[i].end())
            return 1;
        return 0;
    }
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            S[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(S[followerId].find(followeeId) != S[followerId].end())
            S[followerId].erase(followeeId);
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