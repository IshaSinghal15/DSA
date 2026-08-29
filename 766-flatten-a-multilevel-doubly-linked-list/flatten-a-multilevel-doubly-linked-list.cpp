class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return head;
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* child = curr->child;
                Node* next = curr->next;
                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;
                Node* tail = child;
                while (tail->next)
                    tail = tail->next;
                tail->next = next;
                if (next) next->prev = tail;
            }
            curr = curr->next;
        }
        return head;
    }
};