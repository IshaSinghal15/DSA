class WordDictionary {
public:
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;

            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!curr->child[idx])
                curr->child[idx] = new Node();

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    bool dfs(Node* node, string& word, int pos) {
        if (pos == word.size())
            return node->isEnd;

        char c = word[pos];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->child[i] &&
                    dfs(node->child[i], word, pos + 1))
                    return true;
            }

            return false;
        }

        int idx = c - 'a';

        if (!node->child[idx])
            return false;

        return dfs(node->child[idx], word, pos + 1);
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};