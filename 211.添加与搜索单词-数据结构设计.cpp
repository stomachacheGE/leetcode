/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
private:
    struct TrieNode
    {
        TrieNode* children[26];
        bool word_end = false;
        // TrieNode () {
        //     word_end = false;
        //     for (int i=0; i<26; i++) {
        //         children[i] = NULL;
        //     }
        // } 
    };

    TrieNode* root;
    // void getRegxIdxs(string word, int idx, vector<int>& cur, vector<vector<int>>& res) {
    //     if (idx > word.size()) return;
    //     res.push_back(cur);

    //     for (int i=idx; i<word.size(); i++) {
    //         cur.push_back(i);
    //         getRegxIdxs(word, i+1, cur, res);
    //         cur.pop_back();
    //     }
    // }

    bool search(TrieNode* node, string word, int idx) {
        if (node == NULL) return false;
        if (idx >= word.size()) return false;
        
        char c = word[idx];
        if (c == '.') {
            for (auto &child: node->children) {
                // for the case when the last char is '.'
                if (idx == word.size()-1 && child && child->word_end) {
                    return true;
                }
                if (search(child, word, idx+1)) return true;
            }
            return false;
        } 
        node = node->children[c-'a'];
        if (node == NULL) return false;
        if (idx == word.size()-1 && node->word_end) return true;
        if (idx == word.size()-1 && !node->word_end) return false;
        return search(node, word, idx+1);
    }

public:
    // solution one
    // time limit exceed
    // unordered_set<string> set;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        // solution one
        // time limit exceed
        // set.insert(word);
        // string temp = word;
        // vector<vector<int>> idxs;
        // vector<int> cur;
        // getRegxIdxs(word, 0, cur, idxs);
        // for (auto &subset: idxs) {
        //     temp = word;
        //     for (auto &idx: subset) {
        //         temp[idx] = '.';
        //     }
        //     set.insert(temp);
        // }

        // solution two
        // ref.:https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--43/
        TrieNode* parent = root;
        for (auto &c: word) {
            // should not override existing node
            if (parent->children[c-'a'] == NULL) {
                TrieNode* node = new TrieNode();
                parent->children[c-'a'] = node;
                parent = node;
            } else {
                parent = parent->children[c-'a'];
            }
        }
        parent->word_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
        // solution one
        // time limit exceed
        // auto it = set.find(word);
        // if (it == set.end()) return false;
        // return true;

        // solution two
        return search(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end