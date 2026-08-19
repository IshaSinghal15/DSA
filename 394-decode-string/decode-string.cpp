class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;
        string cur;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                nums.push(num);
                strs.push(cur);
                num = 0;
                cur = "";
            } else if (c == ']') {
                int k = nums.top(); nums.pop();
                string prev = strs.top(); strs.pop();

                while (k--) prev += cur;
                cur = prev;
            } else {
                cur += c;
            }
        }

        return cur;
    }
};