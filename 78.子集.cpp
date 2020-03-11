/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    void backtracking(vector<int>& nums, vector<int>& cur, int idx, int size, vector<vector<int>>& res) {
        // if (idx > size) return;
        res.push_back(cur);

        for (int i=idx; i<size; i++) {
            cur.push_back(nums[i]);
            backtracking(nums, cur, i+1, size, res);
            cur.pop_back();
        }

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> res;
       int size = nums.size();
       if (size == 0) return res;
       vector<int> cur;
       backtracking(nums, cur, 0, size, res);
       return res;
    }
};
// @lc code=end

