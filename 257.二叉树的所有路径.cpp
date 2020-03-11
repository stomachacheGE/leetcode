/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void binaryTreePaths(TreeNode* root, string cur, vector<string>& res) {
        if (!root) return;

        cur += "->";
        cur += to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(cur.substr(2, cur.size()-2));
        }

        binaryTreePaths(root->left, cur, res);
        binaryTreePaths(root->right, cur, res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        // solution one
        vector<string> res;
        if (!root) return res;
        string cur;
        binaryTreePaths(root, cur, res);
        return res;
        
    }
};
// @lc code=end

