class Solution {
public:
    unordered_map<int, bool> memo;
    bool solve(int mask, int remain, int maxChoosableInteger) {
        if (memo.count(mask)) return memo[mask];
        for (int x = 1; x <= maxChoosableInteger; x++) {
            int bit = 1 << (x - 1);
            if (mask & bit) continue;
            if (x >= remain) return memo[mask] = true;
            if (!solve(mask | bit, remain - x, maxChoosableInteger)) return memo[mask] = true;
        }
        return memo[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        memo.clear();
        return solve(0, desiredTotal, maxChoosableInteger);
    }
};