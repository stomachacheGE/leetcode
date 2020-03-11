/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // solution three
        // ref.:https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/
        // 股票买卖问题模板
        // states[i][k][0/1]代表的是到第i天做了k次交易并且目前有无股票时候手上的钱
        int n = prices.size();
        int states[n+1][2];
        states[0][0] = 0;
        states[0][1] = INT_MIN;
        for (int i=1; i<=n; i++) {
            states[i][0] = max(states[i-1][0], states[i-1][1] + prices[i-1]);
            states[i][1] = max(states[i-1][1], states[i-1][0] - prices[i-1] - fee);
        }
        return states[n][0];
    }
};
// @lc code=end

