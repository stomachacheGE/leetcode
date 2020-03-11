/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start

struct TrieNode {
        TrieNode* children[26];
        bool word_end = false;
        bool added = false;
};

class Solution {
private:
    void addWord(TrieNode* root, string word) {
        TrieNode* cur = root;
        for (auto c: word) {
            if (cur->children[c-'a']) {
                cur = cur->children[c-'a'];
            } else {
                TrieNode* new_node = new TrieNode();
                cur->children[c-'a'] = new_node;
                cur = new_node;
            }
        }
        cur->word_end = true;
    }

    void backtracking(vector<vector<char>>& board, int i, int j, int m, int n, TrieNode* node, string& cur, vector<vector<bool>>& used, vector<string>& res) {
        if (!node) return;

        cur += board[i][j];
        used[i][j] = true;
        TrieNode* next_node = node->children[board[i][j]-'a'];
        if (next_node && next_node->word_end && !next_node->added) {
            next_node->added = true;
            res.push_back(cur);
        }

        int delta_xs[4] = {-1, 0, 0, 1}, delta_ys[4] = {0, -1, 1, 0};
        for (int idx=0; idx<4; idx++) {
            int ni = i + delta_xs[idx], nj = j + delta_ys[idx];
            if (ni < 0 || ni >= m) continue;
            if (nj < 0 || nj >= n) continue;
            if (!used[ni][nj]) backtracking(board, ni, nj, m, n, next_node, cur, used, res);
        }

        cur = cur.substr(0, cur.size()-1);
        used[i][j] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || board[0].empty() || words.empty()) return res;
        // 构建前缀树
        TrieNode* root = new TrieNode();
        for (auto word: words) {
            addWord(root, word);
        }

        int m = board.size(), n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        string cur="";
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                // 不用重新初始化cur和used
                // 因为回溯法结束时会将状态恢复
                backtracking(board, i, j, m, n, root, cur, used, res);
            }
        }
        return res;
    }
};
// @lc code=end

