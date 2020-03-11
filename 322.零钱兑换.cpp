/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // solution one
        // dynamic programming
        if (coins.empty()) return -1;
        vector<int> states(amount+1, INT_MAX);
        states[0] = 0;
        for (int i=1; i<=amount; i++) {
            for (auto &coin: coins) {
                if (i-coin < 0 || states[i-coin] == INT_MAX) continue;
                states[i] = min(states[i], states[i-coin]+1);
            }
        }
        return states.back() == INT_MAX ? -1 : states.back();

    }
};
// @lc code=end

