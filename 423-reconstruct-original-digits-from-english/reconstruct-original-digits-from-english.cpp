class Solution {
public:
    string originalDigits(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        vector<int> digit(10, 0);
        digit[0] = cnt['z' - 'a']; 
        digit[2] = cnt['w' - 'a']; 
        digit[4] = cnt['u' - 'a'];
        digit[6] = cnt['x' - 'a']; 
        digit[8] = cnt['g' - 'a'];
        digit[3] = cnt['h' - 'a'] - digit[8]; 
        digit[5] = cnt['f' - 'a'] - digit[4]; 
        digit[7] = cnt['s' - 'a'] - digit[6]; 
        digit[1] = cnt['o' - 'a'] - digit[0] - digit[2] - digit[4];
        digit[9] = cnt['i' - 'a'] - digit[5] - digit[6] - digit[8];
        string ans;
        for (int i = 0; i <= 9; i++) {
            ans += string(digit[i], '0' + i);
        }
        return ans;
    }
};