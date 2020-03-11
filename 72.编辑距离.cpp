/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance1(string word1, string word2) {
        // intialization
        int m = word1.size(), n = word2.size();
        // states代表长度分别为i-1，j-1的两个单词的编辑距离
        vector<vector<int>> states(m+1, vector<int>(n+1, INT_MAX));
        states[0][0] = 0;
        for (int i=1; i<=m; i++) {
            states[i][0] = i;
        }
        for (int j=1; j<=n; j++) {
            states[0][j] = j;
        }
        
        // state transfer
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    states[i][j] = min(states[i-1][j-1], states[i-1][j]+1);
                                           // nothing          delete        
                    states[i][j] = min(states[i][j], states[i][j-1]+1);
                                           //                  add          
                } else {
                    states[i][j] = min(states[i-1][j-1]+1, states[i-1][j]+1);
                                           // replace          delete        
                    states[i][j] = min(states[i][j], states[i][j-1]+1);
                                           //                  add    
                }
            }
        }
        
        // answer
        return states[m][n];
    }

    int minDistance(string word1, string word2) {
        // intialization
        int m = word1.size(), n = word2.size();
        // states代表长度分别为i-1，j-1的两个单词的编辑距离
        vector<vector<int>> states(m+1, vector<int>(n+1, INT_MAX));
        states[0][0] = 0;
        for (int i=1; i<=m; i++) {
            states[i][0] = i;
        }
        for (int j=1; j<=n; j++) {
            states[0][j] = j;
        }
        
        // state transfer
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    states[i][j] = states[i-1][j-1];    
                } else {
                    states[i][j] = min(states[i-1][j-1]+1, states[i-1][j]+1);
                                           // replace          delete        
                    states[i][j] = min(states[i][j], states[i][j-1]+1);
                                           //                  add    
                }
            }
        }
        
        // answer
        return states[m][n];
    }
};
// @lc code=end

