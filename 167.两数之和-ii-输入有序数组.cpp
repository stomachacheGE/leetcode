/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // solution one 
        // 双指针O(n)解法
        vector<int> res;
        if (numbers.size() < 2) return res;
        int i = 0, j = numbers.size()-1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return res;

        // solution two
        // binary search O(nlogn) 解法
    }
};
// @lc code=end

