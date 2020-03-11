/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
struct Bucket {
    int min_ = INT_MAX;
    int max_ = INT_MIN;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // solution one
        // 桶排序
        // ref.:https://leetcode-cn.com/problems/maximum-gap/solution/mei-xiang-dao-wo-men-zhi-jian-de-zui-da-jian-ju-ji/
        // ref.:https://leetcode-cn.com/problems/maximum-gap/solution/tong-pai-xu-by-powcai/
        if (nums.size() < 2) return 0;
        int min_val = INT_MAX, max_val = INT_MIN;
        for (auto num: nums) {
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }

        int n = nums.size();
        int gap = max(1, (max_val - min_val) / (n - 1));
        int num_bucket = (max_val - min_val) / gap + 1;
        Bucket buckets[num_bucket];
        for (auto num: nums) {
            int idx = (num - min_val) / gap; // 当前数字该放在那个bucket里
            buckets[idx].min_ = min(buckets[idx].min_, num);
            buckets[idx].max_ = max(buckets[idx].max_, num);
        }

        int prev_max = buckets[0].max_, res = 0;
        for (int i=1; i<num_bucket; i++) {
            if (buckets[i].min_ != INT_MAX) {
                res = max(res, buckets[i].min_ - prev_max); // 当前bucket的最小值减去前一个桶的最大值是候选答案
                prev_max = buckets[i].max_;
            }
        }
        return res;
    }
};
// @lc code=end

