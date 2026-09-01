class MyLinkedList {
    struct Node {
        int val;
        Node* next;

        Node(int v) : val(v), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        Node* cur = head;

        while (index--)
            cur = cur->next;

        return cur->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }

    void addAtTail(int val) {
        Node* node = new Node(val);

        if (!head) {
            head = node;
        } else {
            Node* cur = head;
            while (cur->next)
                cur = cur->next;

            cur->next = node;
        }

        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* cur = head;

        for (int i = 0; i < index - 1; i++)
            cur = cur->next;

        Node* node = new Node(val);
        node->next = cur->next;
        cur->next = node;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node* cur = head;

        for (int i = 0; i < index - 1; i++)
            cur = cur->next;

        Node* temp = cur->next;
        cur->next = temp->next;

        delete temp;
        size--;
    }
};