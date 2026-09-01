class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }
        ListNode* second = head;
        ListNode* temp = first;
        while (temp->next) {
            temp = temp->next;
            second = second->next;
        }
        swap(first->val, second->val);
        return head;
    }
};