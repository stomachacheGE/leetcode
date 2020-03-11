/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        
        // solution one
        // dynamic prgramming
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<bool>> states(n, vector<bool>(n, false));
        for (int i=0; i<n; i++) {
            states[i][i] = true;
            if (i < n-1 && s[i] == s[i+1]) {
                states[i][i+1] = true;
            }
        }
        for (int i=n-3; i>=0; i--) {
            for (int j=i+2; j<n; j++) {
                states[i][j] = states[i+1][j-1] && s[i] == s[j];
            }
        }
        int res = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                res += states[i][j];
            }
        }
        return res;

        // solution two 
        // 马拉车算法，o(n)
        // ref.:https://leetcode-cn.com/problems/palindromic-substrings/solution/hui-wen-zi-chuan-by-leetcode/
        

        // solution three
        // 中心拓展法，o(n**2)

    }
};
// @lc code=end

