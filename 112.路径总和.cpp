/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int cur_sum, int sum) {
        if (!root) return false;
        cur_sum += root->val;
        if (!root->left && !root->right && cur_sum == sum) return true;
        return hasPathSum(root->left, cur_sum, sum) || hasPathSum(root->right, cur_sum, sum);
    }

public:
    bool hasPathSum(TreeNode* root, int sum) {
        // solution one (v2)
        if (!root) return false;
        return hasPathSum(root, 0, sum);
    }
};
// @lc code=end

