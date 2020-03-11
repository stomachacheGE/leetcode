/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // solution one
        // ref.:https://leetcode-cn.com/problems/largest-number/solution/179-by-ikaruga/
        // 关键是设计排序规则

        vector<string> nums_str(nums.size());
        transform(nums.begin(), nums.end(), nums_str.begin(), [](int& num){
            return to_string(num);
        });
        sort(nums_str.begin(), nums_str.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        string res = "0";
        // 此种写法可以处理输入全为0的情况，即[0,0,0]
        for (auto &num: nums_str) {
            res = res == "0" ? num : res + num;
        }
        return res;
    }
};
// @lc code=end

