/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    void postorderTraversal(TreeNode* root, vector<int>& res) {
        if (!root) return;
        postorderTraversal(root->left, res);
        postorderTraversal(root->right, res);
        res.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {

        // solution one (v2)
        // recursion
        // vector<int> res;
        // if (!root) return res;
        // postorderTraversal(root, res);
        // return res;

        // solution two (v2)
        // ref.:https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/er-cha-shu-de-hou-xu-bian-li-by-leetcode/
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            res.push_back(node->val);
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;

        // solution three (v2)
        // 迭代，但是不用reverse (TODO)
        // ref.:https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/er-cha-shu-de-hou-xu-bian-li-by-leetcode/

    }
};
// @lc code=end

