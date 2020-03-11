/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    int getElementIdx(vector<int> inorder, int val) {
        for (int i=0; i<inorder.size(); i++) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }
    TreeNode* buildTree(vector<int>& inorder, int in_s, int in_e, 
                        vector<int>& postorder, int po_s, int po_e) {
        
        if (in_e == in_s) {
            TreeNode* node = new TreeNode(inorder[in_e]);
            return node;
        }

        if (in_e < in_s) return NULL;

        int val = postorder[po_e];
        TreeNode* node = new TreeNode(val);
        int root_idx = getElementIdx(inorder, val);
        if (root_idx == -1) return NULL;
        int left_tree_num = root_idx - in_s;
        node->left = buildTree(inorder, in_s, root_idx-1, postorder, po_s, po_s+left_tree_num-1);
        node->right = buildTree(inorder, root_idx+1, in_e, postorder, po_s+left_tree_num, po_e-1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Solution one
        // naive implementation
        if (inorder.size() == 0) return NULL;
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);

        // Solution two
        // Ref.:https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solution/tu-jie-gou-zao-er-cha-shu-wei-wan-dai-xu-by-user72/
        // getElementIdx可以用一个哈希表来实现
    }
};
// @lc code=end

