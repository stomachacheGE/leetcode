/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {

private:
    struct TrieNode
    {
        TrieNode* children[26];
        bool word_end;
        TrieNode () {
            word_end = false;
            for (int i=0; i<26; i++) {
                children[i] = NULL;
            }
        } 
    };

    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        // solution one
        // ref.:https://leetcode.wang/leetcode-208-Implement-Trie-Prefix-Tree.html
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
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
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (auto &c: word) {
            if (node->children[c-'a'] == NULL) return false;
            node = node->children[c-'a'];
        }
        return node->word_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (auto &c: prefix) {
            if (node->children[c-'a'] == NULL) return false;
            node = node->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

