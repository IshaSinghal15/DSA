class Twitter {
    struct Tweet {
        int id;
        int time;

        Tweet(int id, int time) : id(id), time(time) {}
    };

    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> followees;

    int timer = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId, timer++));
    }

    vector<int> getNewsFeed(int userId) {
        vector<Tweet> allTweets;

        // Own tweets
        for (auto& t : tweets[userId])
            allTweets.push_back(t);

        // Followed users' tweets
        for (int followee : followees[userId]) {
            for (auto& t : tweets[followee])
                allTweets.push_back(t);
        }

        sort(allTweets.begin(), allTweets.end(),
             [](const Tweet& a, const Tweet& b) {
                 return a.time > b.time;
             });

        vector<int> ans;

        for (int i = 0; i < min(10, (int)allTweets.size()); i++)
            ans.push_back(allTweets[i].id);

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};