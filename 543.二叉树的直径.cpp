/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int nodesOnLongestPath(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(nodesOnLongestPath(root->left), nodesOnLongestPath(root->right));
    }

    int nodesOnLongestPath(TreeNode* root, int& res) {
        if (!root) return 0;
        int nodes_left = nodesOnLongestPath(root->left, res);
        int nodes_right = nodesOnLongestPath(root->right, res);
        res = max(res, nodes_left + nodes_right);
        return 1 + max(nodes_left, nodes_right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        // solution one
        // 想法错了，最长路径不一定会经过root
        // if (!root) return 0;
        // return nodesOnLongestPath(root->right) + nodesOnLongestPath(root->left);

        // solution two
        if (!root) return 0;
        int res = 0;
        nodesOnLongestPath(root, res);
        return res;

    }
};
// @lc code=end

