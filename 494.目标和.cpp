/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        // solution one
        // dynamic programming
        int sum = 0;
        for (auto &num: nums) sum += num;
        if (abs(S) > sum) return 0;
        int m = nums.size(), n = 2 * sum + 1;
        // states[i][j]表示前i个数能够构成和为j的数量
        vector<vector<int>> states(m+1, vector<int>(n, 0));
        states[0][sum] = 1;
        for (int i=1; i<=m; i++) {
            for (int j=-sum; j<=sum; j++) {
                int plus = j-nums[i-1]+sum, minus = j+nums[i-1]+sum;
                if ( plus >= 0 && plus < n) states[i][j+sum] += states[i-1][plus];
                if (minus >= 0 && minus < n) states[i][j+sum] += states[i-1][minus];                
            }
        }
        return states[m][S+sum];
    }
};
// @lc code=end

