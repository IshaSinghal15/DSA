class Solution {
public:
    vector<int> getMaxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int remove = nums.size() - k;

        for (int x : nums) {
            while (!st.empty() && remove > 0 && st.back() < x) {
                st.pop_back();
                remove--;
            }
            st.push_back(x);
        }

        st.resize(k);
        return st;
    }

    bool greaterVec(vector<int>& a, int i,
                    vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }

        if (j == b.size())
            return true;

        if (i == a.size())
            return false;

        return a[i] > b[j];
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {
            if (greaterVec(a, i, b, j))
                res.push_back(a[i++]);
            else
                res.push_back(b[j++]);
        }

        return res;
    }

    vector<int> maxNumber(vector<int>& nums1,
                           vector<int>& nums2,
                           int k) {
        vector<int> result;

        int start = max(0, k - (int)nums2.size());
        int end = min(k, (int)nums1.size());

        for (int i = start; i <= end; i++) {
            int j = k - i;

            vector<int> a = getMaxSubsequence(nums1, i);
            vector<int> b = getMaxSubsequence(nums2, j);

            vector<int> candidate = merge(a, b);

            if (result.empty() || candidate > result)
                result = candidate;
        }

        return result;
    }
};