/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
private:
    void backtracking(int k, int n, int idx, int cur_sum, vector<int> cur,
                       vector<vector<int>>& res) {
        
        if (cur_sum > n || cur.size() > k) return;
        if (cur_sum == n && cur.size() == k) {
            res.push_back(cur);
            return;
        }

        for (int i=idx; i<=9; i++) {
            cur.push_back(i);
            cur_sum += i;
            backtracking(k, n, i+1, cur_sum, cur, res);
            cur.pop_back();
            cur_sum -= i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k == 0 || n == 0) return res;
        vector<int> cur;
        int cur_sum = 0;
        backtracking(k, n, 1, cur_sum, cur, res);
        return res;
    }
};
// @lc code=end

