/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    void minDepth(TreeNode* root, int depth, int& min_depth) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL && depth < min_depth) min_depth = depth;
        minDepth(root->left, depth+1, min_depth);
        minDepth(root->right, depth+1, min_depth);
    }

public:
    int minDepth(TreeNode* root) {

        // solution one (v2)
        // if (!root) return 0;
        // if (!root->left) return minDepth(root->right) + 1; // for cases when left child is empty but right child exists
        // if (!root->right) return minDepth(root->left) + 1;
        // return min(minDepth(root->left), minDepth(root->right)) + 1;
        
        // solution two (v2)
        if (root == NULL) return 0;
        int depth = 1, min_depth = INT_MAX;
        minDepth(root, depth, min_depth);
        return min_depth;
    }
};
// @lc code=end

