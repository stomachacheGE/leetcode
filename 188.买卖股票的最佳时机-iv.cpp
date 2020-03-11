/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
private:
    int maxProfitWithoutLimit1(vector<int>& prices) {
        int n = prices.size();
        int states[n+1][2];
        states[0][0] = 0;
        states[0][1] = INT_MIN;
        for (int i=1; i<=n; i++) {
            states[i][0] = max(states[i-1][0], states[i-1][1] + prices[i-1]);
            states[i][1] = max(states[i-1][1], states[i-1][0] - prices[i-1]);
        }
        return states[n][0];
    }

    int maxProfitWithoutLimit(vector<int>& prices) {
        int res = 0, n = prices.size();
        for (int i = 0; i < n - 1; i ++) {
            if (prices[i + 1] > prices[i]){
                res += prices[i + 1] - prices[i];
            }
        }
        return res;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        // solution three
        // ref.:https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/
        // 股票买卖问题模板
        // states[i][k][0/1]代表的是到第i天做了k次交易并且目前有无股票时候手上的钱
        int n = prices.size();
        // 如果k大于天数的一半，说明可以随时交易
        if (k > n/2) return maxProfitWithoutLimit(prices);
        int states[n+1][k+1][2];
        for (int i=0; i<=n; i++) {
            states[i][0][0] = 0;
            states[i][0][1] = INT_MIN;
        }
        for (int i=0; i<=k; i++) {
            states[0][i][0] = 0;
            states[0][i][1] = INT_MIN;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=k; j++) {
                states[i][j][0] = max(states[i-1][j][0], states[i-1][j][1] + prices[i-1]);
                states[i][j][1] = max(states[i-1][j][1], states[i-1][j-1][0] - prices[i-1]);
            }
        }
        return states[n][k][0];
    }
};
// @lc code=end

