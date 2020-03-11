/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 */

// @lc code=start
class Solution {
public:
    int maxProduct1(vector<int>& nums) {
        // solution one
        // 记录以每个节点为终点的最大值
        // 同时记录负数乘积
        // 条件太多不好处理，放弃
        // if (nums.size() == 1) return nums[0];
        // int res = INT_MIN, minus_min = 0, cur_max = 1, minus_counter=0;
        // for (int i=0; i<nums.size(); i++) {
        //     cout << "num=" << nums[i] << ", minus_min=" << minus_min << ", cur_max=" << cur_max << endl;
        //     if (nums[i] == 0) {
        //         cur_max = 0;
        //         minus_min = 0;
        //     } else if (nums[i] < 0) {
        //         minus_counter++;
        //         if (cur_max == 0) {
        //             cur_max = nums[i];
        //             minus_min = nums[i];
        //         } else {
        //             if (minus_counter % 2 == 0) {
        //                 int temp = cur_max;
        //                 cur_max = cur_max * minus_min * nums[i];
        //                 minus_min = temp * nums[i];
        //             } else {
        //                 minus_min = cur_max * nums[i];
        //                 cur_max = nums[i];
        //             }
        //         }
        //     } else {
        //         cur_max = max(nums[i], nums[i] * cur_max);
        //     }
        //     cout << "num=" << nums[i] << ", minus_min=" << minus_min << ", cur_max=" << cur_max << endl; 
        //     if (cur_max > res) res = cur_max;
        // }
        // return res;

        // solution two
        // 每个状态记录以当前节点为终点的子数组的最大最小值
        // 还是有问题，能过152/184
        // 不能过[2,-5,-2,-4,3]
        // if (nums.size() == 1) return nums[0];
        // int res = nums[0], cur_min = nums[0], cur_max = nums[0], minus_counter = nums[0] < 0 ? 1 : 0;
        // int temp_min, temp_max;
        // for (int i=1; i<nums.size(); i++) {
        //     if (nums[i] < 0) { 
        //         minus_counter++;
        //         if (minus_counter % 2 == 1) {
        //             cur_min = cur_max * nums[i];
        //             cur_max = nums[i];
        //         } else {
        //             int temp = cur_max;
        //             cur_max = cur_min * nums[i];
        //             cur_min = temp * nums[i];
        //         }
        //     } else {
        //         cur_max = max(nums[i], cur_max * nums[i]);
        //         cur_min = min(nums[i], cur_min * nums[i]);
        //     }

        //     if (cur_max > res) res = cur_max;
        // }
        // return res;

        // solution three
        // ref.:https://leetcode-cn.com/problems/maximum-product-subarray/solution/hua-jie-suan-fa-152-cheng-ji-zui-da-zi-xu-lie-by-g/
        // 如果当前元素是负数，会将最小值变为最大值，最大值变为最小值
        if (nums.size() == 1) return nums[0];
        int res = nums[0], cur_min = nums[0], cur_max = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] < 0) {
                int temp = cur_max;
                cur_max = cur_min;
                cur_min = temp;
            }

            cur_min = min(nums[i], nums[i] * cur_min);
            cur_max = max(nums[i], nums[i] * cur_max);

            if (cur_max > res) res = cur_max;
        }
        return res;
    }

    int maxProduct(vector<int>& nums) {
        // dynamic programming
        // states即保存乘积最大，也保存乘积最小
        // 因为在遇到负数的最小变最大
        // 额外空间可以是O(1)
        int n = nums.size();
        int res = nums[0];
        vector<int> maxs(n, 0);
        vector<int> mins(n, 0);
        maxs[0] = nums[0];
        mins[0] = nums[0];
        for (int i=1; i<n; i++) {
            if (nums[i] >= 0) {
                maxs[i] = max(nums[i], maxs[i-1] * nums[i]);
                mins[i] = min(nums[i], mins[i-1] * nums[i]);
            } else {
                maxs[i] = max(nums[i], mins[i-1] * nums[i]);
                mins[i] = min(nums[i], maxs[i-1] * nums[i]);
            }
            res = max(res, maxs[i]);
        }
        return res;
    }


};
// @lc code=end

