/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return NULL;
        if (t1 == NULL && t2 != NULL) {
            return t2;
        }
        if (t1 != NULL && t2 == NULL) {
            return t1;
        }
        TreeNode* node = new TreeNode(0);
        TreeNode* left_child, * right_child;
        node->val = t1->val + t2->val;
        left_child = mergeTrees(t1->left, t2->left);
        right_child = mergeTrees(t1->right, t2->right);
        node->left = left_child;
        node->right = right_child;
        return node;
    }
};
// @lc code=end

