/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    void lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q,
                              bool& has_p, bool& has_q, TreeNode*& res) {
        if (!root) return;
        bool l_has_p = false, r_has_p = false, l_has_q = false, r_has_q = false;
        lowestCommonAncestor(root->left, p, q, l_has_p, l_has_q, res);
        lowestCommonAncestor(root->right, p, q, r_has_p, r_has_q, res);
        if (root == p && (l_has_q || r_has_q) && res == NULL) res = root;
        if (root == q && (l_has_p || r_has_p) && res == NULL) res = root;
        if ((l_has_q || r_has_q) && (l_has_p || r_has_p) && res == NULL) res = root;
        if (root == p || l_has_p || r_has_p) has_p = true;
        if (root == q || l_has_q || r_has_q) has_q = true;
        
    }

    void lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q,
                              bool& found, TreeNode*& res) {
        if (!root) return;
        bool l_found = false, r_found = false;
        lowestCommonAncestor(root->left, p, q, l_found, res);
        lowestCommonAncestor(root->right, p, q, r_found, res);
        if (l_found && r_found && res == NULL) res = root;
        if ((root->val == p->val || root->val == q->val) && (l_found || r_found) && res == NULL) res = root;
        found = l_found || r_found || root->val == p->val || root->val == q->val;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // solution one (v2)
        // 后续遍历，看前面是否已经遍历到了p,q
        // 没有充分用树是二叉搜索树的性质
        // TreeNode* res = NULL;
        // bool has_p = false, has_q = false;
        // lowestCommonAncestor(root, p, q, has_p, has_q, res);
        // return res;

        // solution two (v2)
        // 因为给定二叉树p,q是不同的结点
        // 上述方法可以简化
        // TreeNode* res = NULL;
        // bool found = false;
        // lowestCommonAncestor(root, p, q, found, res);
        // return res;

        // solution three (v2)
        // top-down
        // ref.:https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetcod/213511
        if (root == NULL) return NULL;
        if (root == p || root == q) return root;
        
        TreeNode* left_lca  = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_lca = lowestCommonAncestor(root->right, p, q);
        
        if (left_lca == NULL && right_lca == NULL) return NULL;
        else if (left_lca == NULL) return right_lca;
        else if (right_lca == NULL) return left_lca;
        else return root;

    }
};
// @lc code=end

