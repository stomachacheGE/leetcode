/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
private: 
void reverse(string& s, int i, int j) {
    char c;
    while (i < j) {
        c = s[j];
        s[j] = s[i];
        s[i] = c;
        i++;
        j--;
    }
}

public:
    string reverseWords(string s) {
        // solution one
        // 先翻转每个单词，再翻转整个字符串
        int i=0, j=0;

        // cout << s << endl;
        // reverse every word
        while (j < s.size()) {
            while (j < s.size() && s[j] == ' ') {
                j++;
                i++;
            }
            while (j < s.size() && s[j] != ' ') j++;
            reverse(s, i, j-1);
            i = j;
        }
        // cout << s << endl;
        // reverse the whole string
        reverse(s, 0, s.size()-1);
        // cout << s << endl;

        // delete unnecessary spaces
        i = 0, j = 0;
        while (j < s.size()) {
            while (j < s.size() && s[j] == ' ') j++;
            while (j < s.size() && s[j] != ' ') s[i++] = s[j++];
            while (j < s.size() && s[j] == ' ') j++;
            if (j < s.size()) s[i++] = ' ';
        }
        return s.substr(0, i);
    }
};
// @lc code=end

