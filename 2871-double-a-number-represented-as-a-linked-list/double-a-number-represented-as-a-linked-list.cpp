class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        // If doubling the first digit creates a carry,
        // add a new node at the front.
        if (head->val > 4) {
            head = new ListNode(0, head);
        }

        ListNode* curr = head;

        while (curr) {
            curr->val *= 2;

            if (curr->next && curr->next->val > 4) {
                curr->val += 1;
            }

            curr->val %= 10;

            curr = curr->next;
        }

        return head;
    }
};