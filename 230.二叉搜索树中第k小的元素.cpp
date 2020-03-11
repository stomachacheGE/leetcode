/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    void kthSmallest(TreeNode* node, int k, int& cur, int& res) {
        if (node == NULL || cur > k) return;

        kthSmallest(node->left, k, cur, res);
        if (++cur == k) res = node->val;
        kthSmallest(node->right, k, cur, res);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // solution one
        // 中序遍历到第k个退出
        // int res = 0, cur = 0;
        // kthSmallest(root, k, cur, res);
        // return res;

        // solution one (v2)
        // 迭代，并中途退出
        int c = 0;
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            
            while (root) {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();
            if (++c == k) return root->val;
            root = root->right;
        }
        return 0;
    }
};
// @lc code=end

