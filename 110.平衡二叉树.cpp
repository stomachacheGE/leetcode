/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root, int& depth) {
        if (root == NULL) {
            depth = 0;
            return true;
        }

        int left_depth, right_depth;
        bool left_balanced = isBalanced(root->left, left_depth);
        bool right_balanced = isBalanced(root->right, right_depth);
        depth = max(left_depth, right_depth) + 1;
        return abs(left_depth - right_depth) <= 1 && left_balanced && right_balanced;
    }
public:
    bool isBalanced(TreeNode* root) {
        
        // solution one (v2)
        if (!root) return true;
        int depth = 0;
        return isBalanced(root, depth);
    }
};
// @lc code=end

