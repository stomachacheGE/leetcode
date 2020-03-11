/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    void sumOfLeftLeaves(TreeNode* node, int& res) {
        if (!node) return;
        if (node->left && !node->left->left && !node->left->right) res += node->left->val;
        sumOfLeftLeaves(node->left, res);
        sumOfLeftLeaves(node->right, res);

    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        // solution one
        // 用右视图的思想
        if (!root) return 0;
        int res = 0;
        sumOfLeftLeaves(root, res);
        return res;
    }
};
// @lc code=end

