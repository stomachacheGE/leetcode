/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
private:
    bool isInterleave(string s1, int i, string s2, int j, string s3, int p) {
        if (p == s3.size()) return true;
        if (s3[p] != s1[i] && s3[p] != s2[j]) return false;
        if (s3[p] == s1[i] && s3[p] == s2[j]) {
            return isInterleave(s1, i+1, s2, j, s3, p+1) ||
                   isInterleave(s1, i, s2, j+1, s3, p+1);
        }
        if (s3[p] == s1[i]) return isInterleave(s1, i+1, s2, j, s3, p+1);
        if (s3[p] == s2[j]) return isInterleave(s1, i, s2, j+1, s3, p+1);
        return false;

    }
public:
    bool isInterleave1(string s1, string s2, string s3) {
        // initialization
        int m = s1.size(), n = s2.size(), k = s3.size();
        if (k != m+n) return false;
        vector<vector<bool>> states(m+1, vector<bool>(n+1, false));
        states[0][0] = true;
        for (int i=1; i<=m; i++) {
            if (s1[i-1]==s3[i-1]) {
                states[i][0] = true;
            } else {
                break;
            }
        }
        for (int j=1; j<=n; j++) {
            if (s2[j-1]==s3[j-1]) {
                states[0][j] = true;
            }
            else {
                break;
            }
        }
        
        // state transfer
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                //           s3[i+j]          from s1[i]            or      from s[j]
                states[i][j] = (s1[i-1] == s3[i+j-1] && states[i-1][j]) || (s2[j-1]==s3[i+j-1]&& states[i][j-1]);
                    
            }
        }
        return states[m][n];
    }

    bool isInterleave(string s1, string s2, string s3) {

        // solution one
        // brute-force recursion
        // memory limit exceed, pass 99/101
        // if (s3.size() != s1.size() + s2.size()) return false;
        // return isInterleave(s1, 0, s2, 0, s3, 0);

        // solution two
        // dynamic programming
        // states定义前i，j个字符组成的字符串能否交替构成s3
        if (s3.size() != s1.size() + s2.size()) return false;
        int m = s1.size(), n = s2.size();
        vector<vector<bool>> states(m+1, vector<bool>(n+1, false));
        states[0][0] = true;
        for (int i=1; i<=m; i++) {
            if (s3.substr(0,i) == s1.substr(0,i)) states[i][0] = true;
        }
        for (int i=1; i<=n; i++) {
            if (s3.substr(0,i) == s2.substr(0,i)) states[0][i] = true;
        }
        for (int i=1; i<=s3.size(); i++) {
            for (int p=1; p<=min(m,i); p++) { // the num of letters from s1
                int q = i-p;
                if (q < 1 || q > n) continue;
                states[p][q] = (states[p-1][q] && s1[p-1] == s3[i-1]) ||
                               (states[p][q-1] && s2[q-1] == s3[i-1]);
            }
        }
        return states[m][n];
    }
};
// @lc code=end

