/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // solution one
        // brute force
        // if (nums.empty()) return 0;
        // int n = nums.size(), res = 0, cur_sum = 0;
        // for (int i=0; i<n; i++) {
        //     cur_sum = 0;
        //     for (int j=i; j<n; j++) {
        //         cur_sum += nums[j];
        //         if (cur_sum == k) res++;
        //     }
        // }
        // return res;

        // solution two
        // ref.:https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/he-wei-kde-zi-shu-zu-by-leetcode/
        // 用hashmap,时间复杂度是O(n)
        int res = 0, cur_sum = 0;
        // 储存前缀和出现的次数
        unordered_map<int, int> table;
        table[0] = 1;
        for (auto &num: nums) {
            cur_sum += num;
            if (table.count(cur_sum-k)) {
                res += table[cur_sum-k];
            }
            table[cur_sum]++;
        }
        return res;
    }
};
// @lc code=end

