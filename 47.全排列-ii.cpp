/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
private:
    void backtrack(vector<int>& nums, vector<int>& cur, vector<bool>& used, vector<vector<int>>& res) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int i=0; i<nums.size(); i++) {
            
            if (used[i]) {
                continue;
            } 
            
            // 可以理解为重复元素定义了顺序
            // 也就是只有在第一个重复元素被使用后，第二个才使用
            // 其反面是先用第二个，再用第一个，这就和上面规定的顺序重复了
            if (i !=0 && nums[i]==nums[i-1] && !used[i-1]) { 
                continue;
            }
            
            cur.push_back(nums[i]);
            used[i] = true;

            backtrack(nums, cur, used, res);

            cur.pop_back();
            used[i] = false;
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, cur, used, res);
        return res;
    }
};


// @lc code=end

