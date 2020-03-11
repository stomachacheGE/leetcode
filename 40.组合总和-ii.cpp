/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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

            // 去重, 注意i >= idx+1，而不是i >= 1
            if (i >= idx+1 && candidates[i] == candidates[i-1]) {
                continue;
            }

            current.push_back(candidates[i]);
            curSum += candidates[i];

            backtracking(candidates, target, current, i+1, curSum, res); // 不是idx 
            current.pop_back();
            curSum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        // Solution one
        // 注意，解集不能包含重复的组合，所以需要去重
        vector<vector<int>> res;
        if (candidates.size() == 0) return res;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, current, 0, 0, res);
        return res;
    }
};
// @lc code=end

