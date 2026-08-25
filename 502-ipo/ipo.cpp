class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> projects;
        for (int i = 0; i < profits.size(); i++) {
            projects.push({capital[i], profits[i]});
        }
        priority_queue<int> maxProfit;
        for (int i = 0; i < k; i++) {
            while (!projects.empty() && projects.top().first <= w) {
                maxProfit.push(projects.top().second);
                projects.pop();
            }
            if (maxProfit.empty()) break;
            w += maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
};