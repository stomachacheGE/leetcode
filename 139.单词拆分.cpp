/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak1(string s, vector<string>& wordDict) {
        int len = s.size();
        if (len == 0) return true;
        
        // intialization
        int maxWordLen = 0;
        unordered_set<string> dict;
        for (int i=0; i<wordDict.size(); i++) {
            dict.insert(wordDict[i]);
            if (wordDict[i].size() > maxWordLen) {
                maxWordLen = wordDict[i].size();
            }
        }
        
        vector<bool> breakable(len+1, false);
        breakable[0] = true;
        for (int i=1; i<len+1; i++) {
            for (int j=i, count=1; j >= 1 && count <= maxWordLen; j--, count++) {
                if (breakable[j-1]) {
                    string word = s.substr(j-1, count);
                    // cout << word << endl;
                    if (dict.count(word) != 0) {
                        breakable[i] = true;
                        break;
                    }
                }
            }
        }
        return breakable[len];
    }

    bool wordBreak(string s, vector<string>& wordDict) {

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
};
// @lc code=end

