/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // solution one
        // 正向扫描找到右端点
        // 反向扫描找到左端点
        // nums.insert(nums.begin(), INT_MIN);
        // nums.push_back(INT_MAX);
        // int p = 0, q = 1;
        // int cur_max = INT_MIN, cur_min = INT_MAX;
        // bool indicator = true;
        // for (int i=0; i<nums.size(); i++) {
        //     if (nums[i] >= cur_max && !indicator) {
        //         q = i;
        //     }
        //     indicator = nums[i] >= cur_max;
        //     cur_max = max(cur_max, nums[i]);
        // }
        // indicator = true;
        // for (int i=nums.size()-1; i>=0; i--) {
        //     if (nums[i] <= cur_min && !indicator) {
        //         p = i;
        //     }
        //     indicator = nums[i] <= cur_min;
        //     cur_min = min(cur_min, nums[i]);
        // }
        // // cout << "p=" << p << ", q=" << q << endl;
        // return q-p-1;

        // solution two (TODO)
        // ref.:https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leetcode/
        // 中的方法三
        // 找到区间里的最大最小值后，可以扫描数组计数来判断左右端点应该在的位置
        // 区间最小值一定是正向扫描某个下峰处的值，
        // 区间最大值一定是反向扫描某个上峰处的值
        int p = 0, q = nums.size()-1;
        int range_min = INT_MAX, range_max = INT_MIN;
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i+1] < nums[i]) range_min = min(range_min, nums[i+1]);
        }
        for (int i=nums.size()-1; i>0; i--) {
            if (nums[i-1] > nums[i]) range_max = max(range_max, nums[i-1]);
        }
        for (; p<nums.size(); p++) {
            if (nums[p] > range_min) break;
        }
        for (; q>=0; q--) {
            if (nums[q] < range_max) break;
        }
        return q-p <0 ? 0 : q-p+1;
    }
};
// @lc code=end

