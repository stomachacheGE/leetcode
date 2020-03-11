/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // solution one
        // ref.:https://leetcode-cn.com/problems/product-of-array-except-self/solution/chu-zi-shen-yi-wai-shu-zu-de-cheng-ji-by-leetcode/
        // 用输出数组存储当前位左边数的累乘
        // 动态构造当前为右边数的乘积
        vector<int> res(nums.size(), 1);
        for (int i=1; i<nums.size(); i++) {
            res[i] *= res[i-1] * nums[i-1];
        }
        int right = 1;
        for (int i=nums.size()-2; i>=0; i--) {
            right *= nums[i+1];
            res[i] *= right;
        }
        return res;
    }
};
// @lc code=end

