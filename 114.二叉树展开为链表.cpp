/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    TreeNode* flatten_helper(TreeNode* node) {
        // this returns the last node after refroming
        
        if (!node) return NULL;
        // cout << "node=" << node->val << endl;
        
        TreeNode* left_last = flatten_helper(node->left);
        TreeNode* right_last = flatten_helper(node->right);
        TreeNode* temp = node->right;
        if (node->left) {
            node->right = node->left;
            node->left = NULL; // this is necessary
        }
        if (left_last) left_last->right = temp;
        if (right_last) return right_last;
        if (left_last) return left_last;
        return node;
    }

    TreeNode* flatten_helper1(TreeNode* root) {
        // this returns the first node after refroming
        if (root == NULL) return root;
        TreeNode* left  = flatten_helper1(root->left);
        TreeNode* right = flatten_helper1(root->right);
        root->left = NULL;
        if (left == NULL) root->right = right;
        else {
            root->right = left;
            while (left->right) left = left->right;
            left->right = right;
        }
        return root;
    }

public:
    void flatten(TreeNode* root) {
        
        // solution one (v2)
        if (!root) return;
        flatten_helper(root);

        // solution two (v2)
        // if (!root) return;
        // flatten_helper1(root);
    }
};
// @lc code=end

