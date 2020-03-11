/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // solution one
        // 开始想用快排，但是排序的规则不能设定
        // 或者用回溯法遍历所有可能性，但是复杂度爆炸
        // tag提示要用greedy
        // ref.:https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/406-gen-ju-shen-gao-zhong-jian-dui-lie-8xing-dai-m/
        sort(people.begin(), people.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] == rhs[0] ? lhs[1] <= rhs[1] : lhs[0] > rhs[0];
        });
        vector<vector<int>> res;
        for (auto &item: people) {
            res.insert(res.begin()+item[1], item); // insert第一个参数是iterator
        }
        return res;
    }
};
// @lc code=end

