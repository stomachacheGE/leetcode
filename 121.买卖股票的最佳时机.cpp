/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        // Solution One
        // 转化为求maximum subarray的问题
        // 对每一天的利润，考虑是延续之前的利润最大值还是重新开始利润计算
        if (prices.size() == 0) {
            return 0;
        }

        for (int i=0; i<prices.size()-1; i++) {
            prices[i] = prices[i+1] - prices[i]; // profits
        }

        int max_profit = 0;
        int sum_profit = 0;
        for (int j=0; j<prices.size()-1; j++) {
            if (sum_profit + prices[j] < prices[j]) {
                // 重新开始计算利润
                sum_profit = prices[j];
            } else {
                // 延续之前的利润
                sum_profit += prices[j];
            }

            if (sum_profit > max_profit) {
                max_profit = sum_profit;
            }
        }
        return max_profit;
    }

    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        for (int i=0; i<prices.size()-1; i++) {
            prices[i] = prices[i+1] - prices[i];
        }
        int res = max(0, prices[0]);
        for (int i=1; i<prices.size()-1; i++) {
            prices[i] = max(prices[i-1]+prices[i], prices[i]);
            res = max(res, prices[i]);
        }
        return res;
    }
};
// @lc code=end

