/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // solution one
        // 思路错误！！！
        // maximum subarray 的思路
        // if (nums.size() == 0) return 0;
        // // if (nums.size() == 1 && nums[0] <)
        // int start = 0, cur_sum = 0, res = INT_MAX;
        // for (int i=0; i<nums.size(); i++) {
        //     cur_sum = max(cur_sum+nums[i], nums[i]);
        //     if (cur_sum == nums[i]) start = i;
        //     if (cur_sum >= s && (i-start+1) < res) res = i-start+1;
        // } 
        // return res == INT_MAX ? 0 : res;

        // solution two
        // two-pointers
        // ref.:https://leetcode-cn.com/problems/minimum-size-subarray-sum/solution/chang-du-zui-xiao-de-zi-shu-zu-by-leetcode/
        // int i=0, j=0, sum=0, res=INT_MAX;
        // while (j < nums.size()) {
        //     sum += nums[j];
        //     while (sum >= s) {
        //         res = min(res, j-i+1);
        //         sum -= nums[i];
        //         i++;
        //     }
        //     j++;
        // }
        // return res == INT_MAX ? 0 : res;

        // solution three
        // binary search
        // ref.:https://leetcode-cn.com/problems/minimum-size-subarray-sum/solution/chang-du-zui-xiao-de-zi-shu-zu-by-leetcode/
        // skip


        // solution one (v2)
        // sliding window
        // if (nums.size() == 0) return 0;
        // int i = 0, j = 0;
        // int sum = 0, res = INT_MAX;
        // while (j < nums.size()) {
        //     sum += nums[j];
        //     while (sum >= s) {
        //         if (j-i+1 < res) res = j - i + 1;
        //         sum -= nums[i];
        //         i++;
        //     }
        //     j++;
        // }
        // return res == INT_MAX ? 0 : res;

        // solution two (v2)
        // binary search
        if (nums.size() == 0) return 0;
        // nums 统计的是前n项之和，所以在最前面补0
        nums.insert(nums.begin(), 0);
        for (int i=1; i<nums.size(); i++) {
            nums[i] += nums[i-1];
            cout << nums[i] << endl;
        }

        int l = 0, r = nums.size()+1, mid, target;
        int res = nums[nums.size()-1] < s ? 0 : nums.size();
        for (int i=0; i<nums.size(); i++) {
            target = nums[i] + s;
            l = i;
            r = nums.size();
            while (l < r) {
                mid = l + (r - l) / 2;
                if (nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if (l != nums.size()) {
                res = min(l-i, res);
            }
        }
        return res;

    }
};
// @lc code=end

