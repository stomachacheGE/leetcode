/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        // solution one
        // 先全部转换成大写字母，再判断回文串
        for (int i=0; i<s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] += 'A' - 'a';
            }
        }

        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))) i++;
            while (i < j && !((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9'))) j--;
            // cout << "i=" << i << ", j=" << j << endl;
            if (i == j) return true;
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
// @lc code=end

