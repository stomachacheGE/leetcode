/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {

        // solutio one (v2)
        // vector<int> res;
        // if (!root) return res;
        // stack<TreeNode*> s;
        // while (root || !s.empty()) {

        //     while (root) {
        //         res.push_back(root->val);
        //         s.push(root);
        //         root = root->left;
        //     }

        //     root = s.top();
        //     s.pop();
        //     root = root->right;
        // }
        // return res;

        // solution two (v2)
        // morris traversal
        vector<int> res;
        if (!root) return res;
        TreeNode *prev = NULL, *cur = root;
        while (cur) {

            if (cur->left == NULL) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                if (!prev->right) {
                    res.push_back(cur->val);
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return res;
        
    }
};
// @lc code=end

