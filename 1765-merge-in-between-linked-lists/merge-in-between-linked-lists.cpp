class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* beforeA = list1;
        for (int i = 1; i < a; i++) {
            beforeA = beforeA->next;
        }
        ListNode* afterB = beforeA;
        for (int i = a; i <= b; i++) {
            afterB = afterB->next;
        }
        beforeA->next = list2;
        ListNode* tail = list2;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = afterB->next;
        return list1;
    }
};