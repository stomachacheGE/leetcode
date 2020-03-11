/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
private:
    int maxProfit(vector<int> prices, int start, int end) {
        
        for (int i=start; i<end; i++) {
            prices[i] = prices[i+1] - prices[i];
        }
        int res = max(0, prices[start]);
        for (int i=start+1; i<end; i++) {
            prices[i] = max(prices[i-1]+prices[i], prices[i]);
            res = max(res, prices[i]);
        }
        return res;
    }

public:
    int maxProfit(vector<int>& prices) {
        // dynamic programming
        // 将所有交易日分成两段，求每段的最大利润并相加
        // 思路OK，但是因为有很多重复计算，超时了
        // if (prices.size() < 2) return 0;
        // int res = 0, max_left, max_right;
        // res = max(res, maxProfit(prices, 0, prices.size()-1)); // one trade
        // if (prices.size() < 4) return res;
        // for (int i = 1; i < prices.size()-2; i++) {
        //     max_left = maxProfit(prices, 0, i);
        //     max_right = maxProfit(prices, i+1, prices.size()-1);
        //     res = max(res, max_left+max_right);
        // }
        // return res;
        
        // solution two
        // ref.:https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/dong-tai-gui-hua-by-hu-du-3/
        // 减少重复计算

        // solution three
        // ref.:https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/
        // 股票买卖问题模板
        // states[i][k][0/1]代表的是到第i天做了k次交易并且目前有无股票时候手上的钱
        int n = prices.size(), k = 2;
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

