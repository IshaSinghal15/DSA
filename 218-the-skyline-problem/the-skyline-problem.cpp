class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (auto &b : buildings) {
            int l = b[0], r = b[1], h = b[2];
            events.push_back({l, -h}); 
            events.push_back({r, h});
        }
        sort(events.begin(), events.end());
        multiset<int> heights;
        heights.insert(0);
        vector<vector<int>> ans;
        int prevHeight = 0;
        for (int i = 0; i < events.size();) {
            int x = events[i].first;
            while (i < events.size() && events[i].first == x) {
                int h = events[i].second;
                if (h < 0) heights.insert(-h);
                else heights.erase(heights.find(h));
                i++;
            }
            int currHeight = *heights.rbegin();
            if (currHeight != prevHeight) {
                ans.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }
        return ans;
    }
};