/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void recoverTree(TreeNode* root) {

        // solution one (v2)
        // 中序遍历然后确定两个交换元素的位置
        // if (root == NULL) return;
        // stack<TreeNode*> s;
        // TreeNode* node = root;
        // TreeNode* node1 = NULL, *node2 = NULL;
        // TreeNode* prev = new TreeNode(INT_MIN);
        // while (node != NULL || !s.empty()) {

        //     while (node) {
        //         s.push(node);
        //         node = node->left;
        //     }

        //     node = s.top();
        //     s.pop();
        //     if (node1 == NULL && node->val < prev->val) {
        //         node1 = prev;
        //         node2 = node; // must put it here for the case 
        //                       // when two consecutive elements are exchanged, e.g., [1,3,2,4]
        //     }
        //     else if (node1 != NULL && node->val < prev->val) {
        //         node2 = node;
        //     }
        //     prev = node;
        //     node = node->right;
        // }
        // int temp = node2->val;
        // node2->val = node1->val;
        // node1->val = temp;

        // solution two (v2)
        // Morris traversal, time complexity O(n), space complexity O(1)
        // ref.:https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
        // ref.:https://leetcode-cn.com/problems/recover-binary-search-tree/solution/cliang-chong-fang-fa-1shi-yong-di-gui-de-zhong-xu-/
        if (root == NULL) return;
        TreeNode* cur = root;
        TreeNode* node1 = NULL, *node2 = NULL;
        TreeNode* prev = new TreeNode(INT_MIN);
        while (cur) {
            if (cur->left == NULL) {
                if (node1 == NULL && cur->val < prev->val) {
                    node1 = prev;
                    node2 = cur;
                } else if (node1 != NULL && cur->val < prev->val) {
                    node2 = cur;
                }
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode* temp = cur->left;
                while (temp->right && temp->right != cur) {
                    temp = temp->right;
                }

                if (temp->right == NULL) {
                    temp->right = cur;
                    cur = cur->left;
                } else {
                    temp->right = NULL;
                    if (node1 == NULL && cur->val < prev->val) {
                        node1 = prev;
                        node2 = cur;
                    } else if (node1 != NULL && cur->val < prev->val) {
                        node2 = cur;
                    }
                    prev = cur;
                    cur = cur->right; 
                }
            }
        }
        int temp = node2->val;
        node2->val = node1->val;
        node1->val = temp;
    }
};
// @lc code=end

