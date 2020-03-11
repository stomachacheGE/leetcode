/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 != n2) return false;
        // states[i][j][k]代表s1从i开始，s2从j开始的k个字符是否互为扰乱字符串
        vector<vector<vector<bool>>> states(n1, vector<vector<bool>>(n1, vector<bool>(n1+1, false)));
        for (int i=0; i<n1; i++) {
            for (int j=0; j<n1; j++) {
                if (s1[i] == s2[j]) {
                    states[i][j][1] = true;
                }
            }
        }

        for (int len=2; len<=n1; len++) {
            for (int i=0; i<=n1-len; i++) {
                for (int j=0; j<=n1-len; j++) {
                    for (int k=1; k<len; k++) {
                    
                        // 如果没有交换
                        if (states[i][j][k] && states[i+k][j+k][len-k]) {
                            states[i][j][len] = true;
                            break;
                        }
                        // 如果交换了
                        if (states[i][j+len-k][k] && states[i+k][j][len-k]) {
                            states[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return states[0][0][n1];
    }
};
// @lc code=end

