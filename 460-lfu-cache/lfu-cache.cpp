class LFUCache {
    struct Node {
        int key, value, freq;
        Node(int k, int v) : key(k), value(v), freq(1) {}
    };

    int capacity, minFreq;
    unordered_map<int, list<Node>::iterator> mp;
    unordered_map<int, list<Node>> freqList;

    void update(list<Node>::iterator it) {
        int key = it->key;
        int value = it->value;
        int freq = it->freq;

        freqList[freq].erase(it);

        if (freqList[freq].empty() && minFreq == freq)
            minFreq++;

        freqList[freq + 1].push_front(Node(key, value));
        auto newIt = freqList[freq + 1].begin();
        newIt->freq = freq + 1;

        mp[key] = newIt;
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key) {
        if (!mp.count(key))
            return -1;

        auto it = mp[key];
        int value = it->value;

        update(it);
        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (mp.count(key)) {
            auto it = mp[key];
            it->value = value;
            update(it);
            return;
        }

        if (mp.size() == capacity) {
            auto &lst = freqList[minFreq];
            auto last = prev(lst.end());

            mp.erase(last->key);
            lst.pop_back();
        }

        freqList[1].push_front(Node(key, value));
        mp[key] = freqList[1].begin();
        minFreq = 1;
    }
};