/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        // solution one
        // two pointers / sliding window
        // 左指针始终指向当前最长子串的开始位置，
        // 右指针始终指向与当前子串有重复字符的位置
        if (s.size() < 2) return s.size();
        unordered_set<char> table;
        int i = 0, j = 0, res = 0;
        while (j < s.size()) {
            while (j < s.size() && table.find(s[j]) == table.end()) {
                table.insert(s[j]);
                j++;
            }
            if (table.size() > res) res = table.size();
            while (i < s.size() && j < s.size() && s[i] != s[j]) {
                table.erase(s[i]);
                i++;
            }
            i++;
            j++;
        }
        return res;
    }

    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        unordered_set<char> table;
        int i = 0, j = 0, res = 0;
        while (j < s.size()) {

            if (table.count(s[j]) == 0) {
                table.insert(s[j]);
                j++;
                res = max(res, int(table.size()));
                continue;
            }

            while (i < s.size() && s[i] != s[j]) {
                table.erase(s[i]);
                i++;
            }
            i++;
            j++;
        }
        return res;
    }
};
// @lc code=end

