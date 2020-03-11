/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
public:
    TreeNode* invertTree(TreeNode* root) {
        // if (root == NULL) return NULL;
        // if (root->left == NULL && root->right == NULL) return;
        // invertTree(root->left);
        // invertTree(root->right);
        // TreeNode* temp;
        // temp = root->right;
        // root->right = root->left;
        // root->left = temp;
        // return root;

        // solution one (v2)
        if (!root) return root;
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
// @lc code=end

