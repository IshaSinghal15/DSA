class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd = 0, even = 1, res = 0;
        int sum = 0;
        for (int x : arr) {
            sum = (sum + x) & 1;
            if (sum) {
                res += even;
                odd++;
            } else {
                res += odd;
                even++;
            }
            res %= MOD;
        }
        return res;
    }
};