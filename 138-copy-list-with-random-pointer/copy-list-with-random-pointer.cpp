class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* curr = head;

        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while (curr) {
            mp[curr]->next =
                curr->next ? mp[curr->next] : nullptr;

            mp[curr]->random =
                curr->random ? mp[curr->random] : nullptr;

            curr = curr->next;
        }

        return mp[head];
    }
};