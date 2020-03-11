/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    void backtrack(vector<int>& nums, vector<int>& cur, unordered_set<int>& used, vector<vector<int>>& res) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int i=0; i<nums.size(); i++) {
            
            if (used.find(nums[i]) != used.end()) {
                continue;
            } 
            
            cur.push_back(nums[i]);
            used.insert(nums[i]);

            backtrack(nums, cur, used, res);

            cur.pop_back();
            used.erase(nums[i]);
        }
    }

    void backtrack(vector<int>& nums, int idx, vector<vector<int>>& res) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for (int i=idx; i<nums.size(); i++) {

            swap(nums[idx], nums[i]);
            backtrack(nums, idx+1, res); // 注意是idx不是i
            swap(nums[idx], nums[i]);
        }
    }

    void swap(int& i, int& j) {
        int temp = i;
        i = j;
        j = temp;
    }

public:
    vector<vector<int>> permute1(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> used;
        vector<int> cur;
        backtrack(nums, cur, used, res);
        return res;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // ref.:https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode/185944
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
};
// @lc code=end

