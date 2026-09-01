class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;

        int sum = 0;

        while (curr) {
            if (curr->val == 0) {
                tail->next = new ListNode(sum);
                tail = tail->next;
                sum = 0;
            } else {
                sum += curr->val;
            }

            curr = curr->next;
        }

        return ans->next;
    }
};