/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<bool>> getIsPanlindrome(string s) {
        int len = s.size();
        
        // intialization
        vector<vector<bool>> res(len, vector<bool>(len, false));
        for (int i=0; i<len; i++) {
            res[i][i] = true;
            if (i < len-1) res[i][i+1] = s[i] == s[i+1];
        }
        
        // first iterate over length
        for (int l=3; l<=len; l++) {
            // the iterate over index
            // take care of i=len-l
            for (int i=len-l; i>=0; i--) {
                if (s[i] == s[i+l-1]) {
                    res[i][i+l-1] = res[i+1][i+l-2];
                }
            }
        }
        
        return res;
    }
public:
    int minCut1(string s) {
        
        if (s.size() == 0 || s.size() == 1) return 0;
        
        vector<vector<bool>> isPanlindrome = getIsPanlindrome(s);
        
        // initialization
        // Since this is sequence-type DP, 
        // we initialize the states with s.size() + 1
        vector<int> cuts(s.size() + 1);
        iota(cuts.begin(), cuts.end(), -1);
        
        for (int i=1; i<=s.size(); i++) {
            // go backward
            for (int j=i; j>=1; j--) {
                if (isPanlindrome[j-1][i-1]) {
                    cuts[i] = min(cuts[i], cuts[j-1]+1);
                }
            }
        }
        return cuts[s.size()];
    }

    int minCut(string s) {
        // solution one
        // 太复杂不对
        // int n = s.size();
        // if (n <= 1) return 0;
        // vector<vector<pair<int, int>>> states;
        // for (int i=0; i<n; i++) {
        //     states[i][i] = make_pair(0,i);
        //     if (i<n-1 && s[i]==s[i+1]) states[i][i+1] = make_pair(0,i);
        //     else states[i][i+1] = make_pair(1,i+1);
        // }
        // for (int len=3; len<=n; len++) {
        //     for (int i=0; i<n-len+1; i++) {
        //         j = i+len-1;
        //         int temp = states[i][j-1].second;
        //         if (s[j] == s[temp-1]) {
        //             if (states[i][j-1].first + 1 < states[i][temp-2].first+states[temp][j-1].first) {
        //                 states[i][j] = make_pair(states[i][j-1].first + 1, j);
        //             } else {
        //                 states[i][j] = make_pair(states[i][temp-2].first+states[temp][j-1].first, temp-1);
        //             }
        //         } else {
        //             states[i][j] = states[i][j-1] + 1;
        //         }
        //     }
        //     return state[0][n-1];
        // }

        // solution two
        int n = s.size();
        if (n <= 1) return 0;
        vector<vector<bool>> isPanlindromeTable = getIsPanlindrome(s);
        // states存储的以某个元素为结尾的最少分割次数
        vector<int> states(n, 0);
        for (int i=1; i<n; i++) {
            states[i] = i;
        }

        for (int i=1; i<n; i++) {
            // 从之前的任意位置开始判断到当前位置组成的字符串是不是回文串
            for (int j=-1; j<=i-1; j++) {
                if (isPanlindromeTable[j+1][i]) {
                    int prev = j==-1 ? -1 : states[j]; // 注意是-1
                    states[i] = min(states[i], prev+1);
                }
            }
        }
        return states[n-1];
    
    }
};
// @lc code=end

