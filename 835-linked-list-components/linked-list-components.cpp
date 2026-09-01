class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        bool inside = false;
        while (head) {
            if (st.count(head->val)) {
                if (!inside) ans++;
                inside = true;
            }
            else {
                inside = false;
            }
            head = head->next;
        }
        return ans;
    }
};