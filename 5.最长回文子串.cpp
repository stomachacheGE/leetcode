/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome1(string s) {

        // Solution One
        // Ref.:https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode/
        // dynamic programming
        // 用2维表格表示substring是否是palindrome

        if (s.size() == 0) return s;
        
        int num = s.size();
        vector<vector<bool>> dp_table(num, vector<bool>(num, false));
        
        // intialize one-letter and two-letter substrings
        for (int i=0; i<num; i++) {
            dp_table[i][i] = true;
            if (i <= num -1 && s[i+1] == s[i]) {
                dp_table[i][i+1] = true;
            }
        }

        // state transfer 
        for (int i=3; i<=num; i++) {
            for (int j=0; j<=num-i; j++) {
                dp_table[j][j+i-1] = dp_table[j+1][j+i-2] && (s[j] == s[j+i-1]);
            }
        }
        
        // get the final answer
        int res = 0, i_idx, j_idx;
        for (int i=0; i<num; i++) {
            for (int j=i; j<num; j++) {
                if (dp_table[i][j] && j-i+1 > res) {
                    res = j - i + 1;
                    i_idx = i;
                    j_idx = j;
                }
            }
        }
        return s.substr(i_idx, j_idx-i_idx+1);
    }

    string longestPalindrome(string s) {

        // dynamicn programming
        int num = s.size(), p = 0, max_len = 1;
        vector<vector<bool>> table(num, vector<bool>(num, false));
        for (int i=0; i<num; i++) {
            table[i][i] = true;
            if (i+1 < num && s[i+1] == s[i]) {
                table[i][i+1] = true;
                max_len = 2;
                p = i;
            }
        }

        // iterate over len
        // for (int len=3; len<=num; len++) { 
        //     for (int i=0; i<num; i++) {
        //         int j = i+len-1;
        //         if (j >= num) break;
        //         if (s[i]==s[j] && table[i+1][j-1]) {
        //             table[i][j] = true;
        //             if (j-i+1 > max_len) {
        //                 p = i;
        //                 max_len = j-i+1;
        //             }
        //         }
        //     }
        // }

        // iterrate over position
        for (int i=num-3; i>=0; i--) {
            for (int j=i+2; j<num; j++) {
                if (s[i]==s[j] && table[i+1][j-1]) {
                    table[i][j] = true;
                    if (j-i+1 > max_len) {
                        p = i;
                        max_len = j-i+1;
                    }
                }
            }
        }
        
        return s.substr(p, max_len);
    }
};
// @lc code=end

