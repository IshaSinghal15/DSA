class AllOne {
    struct Node {
        int cnt;
        unordered_set<string> keys;
        Node(int c) : cnt(c) {}
    };
    list<Node> buckets;
    unordered_map<string, list<Node>::iterator> mp;
public:
    AllOne() {}
    void inc(string key) {
        if (!mp.count(key)) {
            if (buckets.empty() || buckets.front().cnt != 1) {
                buckets.push_front(Node(1));
            }
            buckets.front().keys.insert(key);
            mp[key] = buckets.begin();
        }
        else {
            auto it = mp[key];
            int newCnt = it->cnt + 1;
            auto next = std::next(it);
            if (next == buckets.end() || next->cnt != newCnt) {
                next = buckets.insert(next, Node(newCnt));
            }
            next->keys.insert(key);
            mp[key] = next;
            it->keys.erase(key);
            if (it->keys.empty()) buckets.erase(it);
        }
    }
    void dec(string key) {
        auto it = mp[key];
        if (it->cnt == 1) {
            it->keys.erase(key);
            mp.erase(key);
            if (it->keys.empty()) buckets.erase(it);
            return;
        }
        int newCnt = it->cnt - 1;
        auto prev = (it == buckets.begin()) ? buckets.end() : std::prev(it);
        if (it == buckets.begin() || prev->cnt != newCnt) {
            prev = buckets.insert(it, Node(newCnt));
        }
        prev->keys.insert(key);
        mp[key] = prev;
        it->keys.erase(key);
        if (it->keys.empty()) buckets.erase(it);
    }
    string getMaxKey() {
        if (buckets.empty()) return "";
        return *buckets.back().keys.begin();
    }
    string getMinKey() {
        if (buckets.empty()) return "";
        return *buckets.front().keys.begin();
    }
};