/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // sliding window + counter
        vector<int> res;
        if (s.size() < p.size()) return res;
        unordered_map<char, int> counter_p, counter_s;
        for (auto &c: p) {
            counter_p[c]++;
        }
        int j=0;
        for (int i=0; i<=s.size()-p.size(); i++) {
            while (j<i+p.size()) {
                counter_s[s[j]]++;
                j++;
            }
            if (counter_s == counter_p) {
                res.push_back(i);
            }
            counter_s[s[i]]--;
            if (counter_s[s[i]] == 0) {
                counter_s.erase(s[i]);
            }
        }
        return res;
         
    }
};
// @lc code=end

