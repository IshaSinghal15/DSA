class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[')
            return NestedInteger(stoi(s));

        stack<NestedInteger> st;
        int num = 0;
        bool negative = false;
        bool hasNum = false;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '[') {
                st.push(NestedInteger());
            }
            else if (c == '-') {
                negative = true;
            }
            else if (isdigit(c)) {
                num = num * 10 + (c - '0');
                hasNum = true;
            }
            else if (c == ',' || c == ']') {
                if (hasNum) {
                    if (negative) num = -num;
                    st.top().add(NestedInteger(num));
                    num = 0;
                    negative = false;
                    hasNum = false;
                }

                if (c == ']' && st.size() > 1) {
                    NestedInteger curr = st.top();
                    st.pop();
                    st.top().add(curr);
                }
            }
        }

        return st.top();
    }
};