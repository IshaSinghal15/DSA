class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int mid = (n - 1) / 2;
        int high = n - 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) nums[i] = sorted[mid--];
            else nums[i] = sorted[high--];
        }
    }
};