/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counter(26, 0);
        for (auto &c: s) {
            counter[c-'a']++;
        }
        for (auto &c: t) {
            counter[c-'a']--;
        }
        for (auto &count: counter) {
            if (count != 0) return false;
        }
        return true;
    }
};
// @lc code=end

