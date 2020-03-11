/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        // solution one
        // 排序，然后从前向后判断
        // sort(citations.begin(), citations.end());
        // reverse(citations.begin(), citations.end());
        sort(citations.begin(), citations.end(), [](const int &a, const int &b) {
            return a > b;
        });
        int i = 0;
        while (i < citations.size()) {
            if (citations[i] < i+1) break;
            i++;
        }
        return i;
    }
};
// @lc code=end

