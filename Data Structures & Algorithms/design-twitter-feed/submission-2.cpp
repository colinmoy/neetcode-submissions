class Twitter {
public:
    Twitter() {
        follows.clear();
        tweets.clear();
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        follows[userId].insert(userId);
        tweets[userId].insert(tweets[userId].begin(), {time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<pair<int, int>> pq;
        for (int id : follows[userId]) {
            for (int i = 0; i < min(10, (int) tweets[id].size()); i++) {
                pq.push(tweets[id][i]);
            }
        }
        for (int i = 0; i < 10 && !pq.empty(); i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        follows[followerId].erase(followeeId);
    }

private:
    unordered_map<int, set<int>> follows;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int time;
};
