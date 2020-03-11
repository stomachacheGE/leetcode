/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    void convertBST(TreeNode* root, int& cur) {
        if (!root) return;
    
        convertBST(root->right, cur);
        int temp = root->val;
        root->val += cur;
        cur += temp;
        convertBST(root->left, cur);
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {

        int cur = 0;
        convertBST(root, cur);
        return root;
    }
};
// @lc code=end

