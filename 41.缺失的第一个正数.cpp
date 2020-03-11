/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        // solution one
        // hashmap
        // 注意到答案必定在[1, n+1]的范围内
        // 依次判断备选答案是否在数组中
        // 空间复杂度O(n),不符合要求
        // int n = nums.size();
        // unordered_set<int> s;
        // for (auto &num: nums) {
        //     s.insert(num);
        // }
        // for (int i=1; i<=n; i++) {
        //     if (s.count(i) == 0) {
        //         return i;
        //     }
        // }
        // return n+1;

        // solution two
        // 用自身数组代替set
        // 将数字i放在数组中i的位置
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        for (int i=1; i<nums.size(); i++) {         // this cannot be nums[i] != i, consider [1,1]
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i]] != nums[i]) {
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        int res = 1;
        while (res <= n) {
            if (nums[res] != res) return res;
            res++;
        }
        return res;
    }
};
// @lc code=end

