/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum2(vector<int>& nums) {
        // solution one (v2)
        // 将问题转化为two sum
        // 排序后，从左至右固定每个元素，然后在其后的元素里找two sum
        // 注意去重
        vector<vector<int>> res;
        vector<int> cur;
        if (nums.size() < 3) return res;
        int m = 0, i, j, target;
        sort(nums.begin(), nums.end());
        while (m < nums.size()-2) {
            // 去重
            while (m > 0 && m < nums.size()-2 && nums[m] == nums[m-1]) m++;
            if (m >= nums.size()-2) break;
            // cout << "m = " << m << endl;
            i = m + 1;
            j = nums.size() - 1;
            while (i < j) {
                while (i > m+1 && i < nums.size() - 1 && nums[i] == nums[i-1]) i++;
                while (j < nums.size() - 1 && j >= 0 && nums[j] == nums[j+1]) j--;
                if (i >= j) break;
                if (nums[i] + nums[j] == -nums[m]) {
                    cur = {nums[m], nums[i], nums[j]};
                    res.push_back(cur);
                    i++;
                    j--;
                } else if (nums[i] + nums[j] < -nums[m]) {
                    i++;
                } else {
                    j--;
                }
            }
            m++;
        }
        return res; 
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        // 将问题转化为two sum
        // 排序后，从左至右固定每个元素，然后在其后的元素里找two sum
        // 注意去重
        vector<vector<int>> res;
        vector<int> cur;
        if (nums.size() < 3) return res;
        int m = 0, i, j, target;
        sort(nums.begin(), nums.end());
        while (m < nums.size()-2) {
            // 去重
            while (m > 0 && m < nums.size()-2 && nums[m] == nums[m-1]) m++;
            if (m >= nums.size()-2) break;
            // cout << "m = " << m << endl;
            i = m + 1;
            j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == -nums[m]) {
                    cur = {nums[m], nums[i], nums[j]};
                    res.push_back(cur);
                    while (i < j && nums[i] == nums[i+1]) i++;
                    while (i < j && nums[j] == nums[j-1]) j--;
                    i++;
                    j--;
                } else if (nums[i] + nums[j] < -nums[m]) {
                    i++;
                } else {
                    j--;
                }
               
            }
            m++;
        }
        return res; 
    }
};
// @lc code=end

