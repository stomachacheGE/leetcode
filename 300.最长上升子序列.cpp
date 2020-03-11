/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // solution one (v2)
        // dynamic programming
        if (nums.size() < 2) return nums.size();
        vector<int> state(nums.size(), 1); // initialize with 1
        int res = 1;
        for(int i=1; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j]) {
                    state[i] = max(state[i], state[j]+1);
                    res = max(state[i], res);
                }
            }
        }
        return res;

        // solution two (v2)
        // ref.:https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-2/
        // dynamic programming + binary search (TODO)
    }
};
// @lc code=end

