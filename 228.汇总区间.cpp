/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // solution one
        // 两个指针
        vector<string> res;
        if (nums.size() == 0) return res;
        int start = 0, end = 0;
        string cur;
        while (end < nums.size()) {
            
            while (end < nums.size() - 1 && nums[end+1] == nums[end] + 1) {
                end++;
            }

            if (start == end) {
                res.push_back(to_string(nums[start]));
            } else {
                cur = to_string(nums[start]);
                cur += "->";
                cur += to_string(nums[end]);
                res.push_back(cur);
            }
            
            end++;
            start = end;
        }
        return res;
    }
};
// @lc code=end

