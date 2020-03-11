/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void pathSum(TreeNode* root, int sum, int cur_sum, vector<int>& path, vector<vector<int>>& res) {
        if (root == NULL) return;

        cur_sum += root->val;
        path.push_back(root->val);

        if (cur_sum == sum && root->left == NULL && root->right == NULL) {
            res.push_back(path);
        }

        pathSum(root->left, sum, cur_sum, path, res);
        pathSum(root->right, sum, cur_sum, path, res);

        cur_sum -= root->val;
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        vector<int> path;
        pathSum(root, sum, 0, path, res);
        return res;
    }
};
// @lc code=end

