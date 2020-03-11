/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    void backtracking(vector<int>& candidates, int target, vector<int>& current, int idx, int curSum, vector<vector<int>>& res) {
        if (curSum > target) return;
        if (curSum == target) {
            res.push_back(current);
            return;
        }

        for (int i=idx; i<candidates.size(); i++) {
            current.push_back(candidates[i]);
            curSum += candidates[i];
            backtracking(candidates, target, current, i, curSum, res); // 注意不是i+1
            current.pop_back();
            curSum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        // Solution one
        // 注意，解集不能包含重复的组合，所以需要去重
        vector<vector<int>> res;
        if (candidates.size() == 0) return res;
        vector<int> current;
        backtracking(candidates, target, current, 0, 0, res);
        return res;
    }
};
// @lc code=end

