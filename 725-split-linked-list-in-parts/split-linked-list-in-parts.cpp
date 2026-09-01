class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        int base = n / k;
        int extra = n % k;
        vector<ListNode*> ans(k);
        temp = head;
        for (int i = 0; i < k; i++) {
            ans[i] = temp;
            int size = base + (i < extra ? 1 : 0);
            for (int j = 1; j < size && temp; j++) {
                temp = temp->next;
            }
            if (temp) {
                ListNode* next = temp->next;
                temp->next = nullptr;
                temp = next;
            }
        }
        return ans;
    }
};