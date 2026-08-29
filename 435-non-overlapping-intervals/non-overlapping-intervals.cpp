class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int keep = 0;
        int end = INT_MIN;

        for (auto& interval : intervals) {
            if (interval[0] >= end) {
                keep++;
                end = interval[1];
            }
        }

        return intervals.size() - keep;
    }
};