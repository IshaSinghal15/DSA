class NestedIterator {
    stack<NestedInteger> st;

public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--)
            st.push(nestedList[i]);
    }

    int next() {
        int val = st.top().getInteger();
        st.pop();
        return val;
    }

    bool hasNext() {
        while (!st.empty() && !st.top().isInteger()) {
            vector<NestedInteger> list = st.top().getList();
            st.pop();

            for (int i = list.size() - 1; i >= 0; i--)
                st.push(list[i]);
        }

        return !st.empty();
    }
};