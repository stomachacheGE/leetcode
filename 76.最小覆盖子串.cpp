/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // solution one 
        // 从头到尾，检查窗口内的子串是否满足条件
        // 为了避免直接比较两个ordered_map, 通过match的key的个数来比较
        int m = s.size(), n = t.size();
        if (m < n || n == 0) return "";
        unordered_map<char, int> m1, m2;
        for (auto &c: t) {
            m1[c] += 1;
        }

        int i = 0, j = 0, matched = 0;
        string res = s;
        bool found = false;
        while (j < s.size()) {

            while (i < s.size() && m1.find(s[i]) == m1.end()) i++;
            cout << "i=" << i << endl;
            if (i == s.size()) break;

            while (j < s.size() && m1.find(s[j]) == m1.end()) j++;
            
            m2[s[j]] += 1;
            if (m2[s[j]] == m1[s[j]]) matched++;
            // cout << "j=" << j << ", matched=" << matched << endl;

            // use while to make sure the remaing string is not valid
            while (matched == m1.size()) {
                found = true;
                // cout << "matched, i=" << i << ", j=" << j << endl;
                while (i < s.size() && m1.find(s[i]) == m1.end()) i++;
                string cur_str = s.substr(i, j-i+1);
                if (cur_str.size() < res.size()) {
                    res = cur_str;
                }
                m2[s[i]]--;
                if (m2[s[i]] < m1[s[i]]) matched--;
                i++;
            } 
            j++;
        }
        return found ? res : "";
    }
};
// @lc code=end

