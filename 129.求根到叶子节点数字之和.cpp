/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    void sumNumbers(TreeNode* root, int& num, int& res) {
        if (root == NULL) return;

        num = num * 10 + root->val;
        if (root->left == NULL && root->right == NULL) res += num;

        sumNumbers(root->left, num, res);
        sumNumbers(root->right, num, res);

        num /= 10;
    }
public:
    int sumNumbers(TreeNode* root) {
        // if (root == NULL) return 0;
        // int res = 0, num = 0;
        // sumNumbers(root, num, res);
        // return res;

        // solution one (v2)
        if (!root) return 0;
        int res = 0;
        int cur = 0;
        sumNumbers1(root, cur, res);
        return res;
    }

    void sumNumbers1(TreeNode* root, int cur, int& res) {
        if (!root) return;

        cur = cur * 10 + root->val;
        if (!root->left && !root->right) {
            res += cur;
        }

        sumNumbers1(root->left, cur, res);
        sumNumbers1(root->right, cur, res);
    }
};
// @lc code=end

