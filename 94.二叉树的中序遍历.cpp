/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void inorderTraversal(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorderTraversal(root->left, res);
        res.push_back(root->val);
        inorderTraversal(root->right, res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // solution one (v2)
        // recursion
        // vector<int> res;
        // inorderTraversal(root, res);
        // return res;

        // solution two (v2)
        // stack
        stack<TreeNode*> s;
        vector<int> res;
        if (root == NULL) return res;
        TreeNode* node = root;
        while (node != NULL || !s.empty()) {

            while (node) {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            s.pop();
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};
// @lc code=end

