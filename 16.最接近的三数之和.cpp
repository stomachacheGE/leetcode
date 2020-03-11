/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Solution One
        // two pointers
        // 先排序，然后从左到有固定一个数，
        // two pointers分别指向其后第一个数和最后一个数
        // 如果三数之和小于target，向右移动左指针
        // 如果三数之和大于target，向左移动右指针
        // 在过程中记录最接近的和

        sort(nums.begin(), nums.end());
        int res, m, n, distance = INT_MAX;

        for (int i=0; i < nums.size()-2; i++) {
            m = i+1;
            n = nums.size() - 1;
            while (m < n) {
                int sum = nums[i] + nums[m] + nums[n];
                if (abs(sum - target) < distance) {
                    res = sum;
                    distance = abs(sum - target);
                }
                if (sum < target) m++;
                else if (sum > target) n--;
                else return res;
            }
        }
        return res;
    }
};
// @lc code=end

