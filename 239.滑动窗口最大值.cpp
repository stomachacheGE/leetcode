/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // solution one
        // ref.:https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetcode-3/
        // if (nums.empty()) return nums;
        // vector<int> res;
        // deque<int> q;
        // int cur = INT_MIN, idx = 0;
        // while (idx < k) {
        //     while (!q.empty() && nums[q.back()] < nums[idx]) {
        //         q.pop_back();
        //     }
        //     q.push_back(idx);
        //     idx++;
        // }
        // res.push_back(nums[q[0]]);
        // while (idx < nums.size()) {
        //     while (!q.empty() &&  q[0] <= idx-k) {
        //         q.pop_front(); // remove elements that are out of range
        //     }
        //     while (!q.empty() && nums[q.back()] < nums[idx]) { 
        //         q.pop_back(); // remove the elements that are smaller than cur
        //                       // note we remove from right to left
        //     }
        //     q.push_back(idx);
        //     res.push_back(nums[q[0]]);
        //     idx++;
        // }
        // return res;

        // solution two
        // ref.:ref.:https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetcode-3/
        // 把数组分成k大的小块
        // 用left数组表示每一块块头到当前位置的最大值
        // 用right数组表示每一块块尾到当前位置的最大值
        // 最后遍历时比较left和right的最大值即为当前结果
        if (nums.empty()) return nums;
        int n = nums.size(), cur_max = INT_MIN;
        vector<int> left(n, 0), right(n, 0), res;
        for (int i=0; i<n; i++) {
            if (i % k == 0) {
                cur_max = nums[i];
            } else {
                cur_max = max(cur_max, nums[i]);
            }
            left[i] = cur_max;
        }
        for (int j=n-1; j>=0; j--) {
            if (j == n-1 || (j+1) % k == 0) {
                cur_max = nums[j];
            } else {
                cur_max = max(cur_max, nums[j]);
            }
            right[j] = cur_max;
        }

        for (int i=0; i<=n-k; i++) {
            res.push_back(max(right[i], left[i+k-1]));
        }
        return res;
    }
};
// @lc code=end

