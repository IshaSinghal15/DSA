class SummaryRanges {
    set<int> nums;

public:
    SummaryRanges() {}
    void addNum(int value) {
        nums.insert(value);
    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        if (nums.empty()) return ans;
        auto it = nums.begin();
        int start = *it;
        int prev = *it;
        ++it;
        for (; it != nums.end(); ++it) {
            if (*it == prev + 1) prev = *it;
            else {
                ans.push_back({start, prev});
                start = prev = *it;
            }
        }
        ans.push_back({start, prev});
        return ans;
    }
};