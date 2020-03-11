/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // solution one
        // 摩尔投票法升级版
        // ref.:https://leetcode-cn.com/problems/majority-element-ii/solution/majority-voting-algorithm-by-powcai/
        // ref.:https://leetcode-cn.com/problems/majority-element-ii/solution/liang-fu-dong-hua-yan-shi-mo-er-tou-piao-fa-zui-zh/
        if (nums.size() <= 1) return nums;
        int cand1 = nums[0], cand2 = nums[0], count1 = 0, count2 = 0;
        // stage 1: vote
        for (auto num: nums) {
            if (num == cand1) {
                count1++;
                continue;
            }

            if (num == cand2) {
                count2++;
                continue;
            }

            if (count1 == 0) {
                cand1 = num;
                count1++;
                continue;
            }

            if (count2 == 0) {
                cand2 = num;
                count2++;
                continue;
            }

            count1--;
            count2--;
        }

        // stage 2: confirm
        count1 = 0;
        count2 = 0;
        for (auto num: nums) {
            if (num == cand1) count1++;
            if (num == cand2) count2++;
        }
        
        vector<int> res;
        int n = nums.size();
        if (count1 > n / 3) res.push_back(cand1);
        if (count2 > n / 3 && cand1 != cand2) res.push_back(cand2); // remove duplicates
        return res;
    }
};
// @lc code=end

