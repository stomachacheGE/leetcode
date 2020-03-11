/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {

    bool wordBreak139(string s, vector<string>& wordDict) {

        // solution one
        unordered_set<string> dict;
        int max_len = 0;
        for (auto &word: wordDict) {
            dict.insert(word);
            max_len = max(max_len, int(word.size()));
        }
        int n = s.size();
        vector<bool> states(n+1, false);
        states[0] = true;
        for (int i=1; i<=n; i++) {
            for (int len=1; len<=max_len; len++) {
                if (i-len < 0) break; 
                states[i] = states[i] || (states[i-len] && dict.count(s.substr(i-len,len)));
                // cout << "state " << i << ": " << states[i] << endl;
            }
        }
        return states[n];
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // solution one
        // 先看可行性再划分，不然过不了第31个case
        vector<string> res;
        if (!wordBreak139(s, wordDict)) return res;
        unordered_set<string> dict;
        int max_len = 0;
        for (auto &word: wordDict) {
            dict.insert(word);
            max_len = max(max_len, int(word.size()));
        }
        int n = s.size();
        vector<bool> states(n+1, false);
        vector<vector<vector<int>>> idxs(n+1);
        states[0] = true;
        idxs[0] = vector<vector<int>>{{}};
        for (int i=1; i<=n; i++) {
            for (int len=1; len<=max_len; len++) {
                if (i-len < 0) break; 
                if(states[i-len] && dict.count(s.substr(i-len,len))) {
                    for (auto &idx: idxs[i-len]) {
                        vector<int> temp = idx; // has to use temp
                        temp.push_back(i);
                        idxs[i].push_back(temp);
                    }
                    states[i] = true;
                    // cout << "i=" << i << ", len=" << len << endl;
                }
            }
        }

        for (auto &locs: idxs[n]) {
            string temp = s;
            for (int i=0; i<locs.size()-1; i++) {
                temp.insert(locs[i]+i, 1, ' ');
            }
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end

