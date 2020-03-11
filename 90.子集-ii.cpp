/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
private:
    void backtracking(vector<int>& nums, vector<int>& cur, int idx, vector<vector<int>>& res) {
        
        if (idx > nums.size()) return;
        
        res.push_back(cur);

        for(int i=idx; i<nums.size(); i++) {
            if (i>idx && nums[i] == nums[i-1]) continue; // this is the key
            cur.push_back(nums[i]);
            backtracking(nums, cur, i+1, res);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtracking(nums, cur, 0, res);
        return res;
    }
};
// @lc code=end

