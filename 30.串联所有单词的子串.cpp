/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // solution one
        // ref.:https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/chuan-lian-suo-you-dan-ci-de-zi-chuan-by-powcai/
        // 滑动窗口+hashmap存储每个单词出现的次数
        vector<int> res;
        if (s.size() == 0 || words.size() == 0) return res;
        int word_len = words[0].size(), word_num = words.size();
        int total_len = word_len * word_num;
        int window_size = 0, m, n;
        if (total_len > s.size()) return res;

        // counter
        unordered_map<string, int> counter;
        // for (auto &word: words) {
        //     if (counter.find(word) == counter.end()) {
        //         counter[word] = 0;
        //     } else {
        //         counter[word]++;
        //     }
        // }
        for (auto &word: words) {
            counter[word]++;
        }

        // string could start from any position
        // NOTE: the following works, but it is not sliding window, beats 53%
        // for (int i=0; i<word_len; i++) {
        //     for (int j=i; j<=s.size()-total_len; j+=word_len) {
        //         window_size = 0;
        //         unordered_map<string, int> cur_counter;
        //         m = j;
        //         n = j;
        //         while (window_size < total_len) {
        //             // cout << "i=" << i << ", j=" << j << ", m=" << m << ", n=" << n << endl;
        //             n += word_len;
        //             string cur_word = s.substr(m, word_len);
        //             if (counter.find(cur_word) == counter.end()) break;
        //             cur_counter[cur_word]++;
        //             if (cur_counter[cur_word] > counter[cur_word]) break;
        //             m += word_len;
        //             window_size += word_len;
        //         }
        //         if (window_size == total_len) res.push_back(j);
        //     }
        // }
        // sliding window version
        for (int i=0; i<word_len; i++) { // NOTE iterate over word_len, not s_len
            unordered_map<string, int> cur_counter;
            m = i;
            n = i;
            while (n <= s.size() - word_len) {
                // cout << "i=" << i << ", m=" << m << ", n=" << n << endl;
                string cur_word = s.substr(n, word_len);
                n += word_len;
                if (counter.count(cur_word) == 0) {
                    m = n;
                    cur_counter.clear();
                    continue;
                }

                cur_counter[cur_word]++;
                while (cur_counter[cur_word] > counter[cur_word]) {
                    string a_word = s.substr(m, word_len);
                    cur_counter[a_word]--;
                    m += word_len;
                }
                if (n-m == total_len) res.push_back(m); // note this is a good exit condition
            }
        }
        return res;
    }
};
// @lc code=end

