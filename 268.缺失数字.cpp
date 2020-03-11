/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int cur_sum = 0, sum = 0;
        for (int i=0; i<=nums.size(); i++) {
            if (i < nums.size()) cur_sum += nums[i];
            sum += i;
        }
        return sum - cur_sum;

    }
};
// @lc code=end

