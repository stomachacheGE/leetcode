/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        // 注意，本题的最大路径不要求必须包含叶节点，
        // 并且路径可以包含从子节点到父节点，再到另一个子节点的路径

        // Solution one:
        // Ref.:https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/comments/

        // 类似后序遍历的思想，在每一个节点考察：
        // 1）判断是不是最大路径上的节点，如果是，可以有以下几种情况：
        //    a. 最大路径上只有这个节点
        //    b. 最大路径上包含这个节点，及这个节点的左子树上某条路径
        //    c. 最大路径上包含这个节点，及这个节点的右子树上某条路径
        //    d. 最大路径上包含这个节点，及这个节点连接了左右子树上的某条路径
        //    在以上b,c,d情况中，子树上的那条路径必定是以子节点为起始点的最大路径
        // 2) 递归求得以此节点为起始点的最大路径和，此路径不一定包含根节点，需要
        //    将路径和与0比较进行剪枝
    
        getOneSideMaxSumFromNode(root);
        return res;

    }

    int getOneSideMaxSumFromNode(TreeNode* node) {

        if (node == nullptr) {
            return 0;
        }

        int left_sum = max(0, getOneSideMaxSumFromNode(node->left)); // 剪枝求和
        int right_sum = max(0, getOneSideMaxSumFromNode(node->right));

        int res_candidate = left_sum + right_sum + node->val;
        if (res_candidate > res) {
            res = res_candidate;
        }

        return max(left_sum, right_sum) + node->val;
    }
};
// @lc code=end

