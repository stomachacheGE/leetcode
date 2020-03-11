/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> trees;
        if (start > end) {
            trees.push_back(NULL);
            return trees;
        }

        for (int i=start; i<=end; i++) {
            vector<TreeNode*> leftTrees = generateTrees(start, i-1);
            vector<TreeNode*> rightTrees = generateTrees(i+1, end);

            for (auto &leftChild: leftTrees) {
                for (auto &rightChild: rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftChild;
                    root->right = rightChild;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }

    vector<TreeNode*> generateTrees1(int s, int e) {
        vector<TreeNode*> res;
        if (s > e) {
            res.push_back(NULL);
            return res;
        }

        if (s == e) {
            TreeNode* node = new TreeNode(s);
            res.push_back(node);
            return res;
        } 

        for (int i=s; i<=e; i++) {
            vector<TreeNode*> left_children = generateTrees(s, i-1);
            vector<TreeNode*> right_children = generateTrees(i+1, e);
            for (auto &left_child: left_children) {
                for (auto &right_child: right_children) {
                     TreeNode* node = new TreeNode(i);
                     node->left = left_child;
                     node->right = right_child;
                     res.push_back(node);
                }
            }
        }
        return res;
    }

    TreeNode* clone(TreeNode* root, int offset) {
        if (!root) return NULL;
        TreeNode* new_root = new TreeNode(root->val + offset);
        new_root->left = clone(root->left, offset);
        new_root->right = clone(root->right, offset);
        return new_root;
    }

public:
    vector<TreeNode*> generateTrees2(int n) {

        // solution one
        // Ref.:https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/bu-tong-de-er-cha-sou-suo-shu-ii-by-leetcode/
        // 把1～n的每个数字作为根结点，左边的数字构成左子树，右边的数构成右子树，递归求得
        // vector<TreeNode*> res;
        // if (n == 0) return res;
        // return generateTrees(1, n);
        
        // Solution two
        // Ref.:https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-2-7/
        // 动态规划的方法，但是思路比较绕(TODO)

        // solution one (v1)
        // 把1到n的每个数字当作根结点构造二叉搜索树
        vector<TreeNode*> res;
        if (n == 0) return res;
        return generateTrees1(1, n);
    }

    vector<TreeNode*> generateTrees(int n) {
        // dynamic programming
        vector<TreeNode*> res;
        if (n == 0) return res;
        vector<vector<TreeNode*>> states(n+1);
        states[0].push_back(NULL);
        for (int i=1; i<=n; i++) {
            vector<TreeNode*> cur;
            // 分别以1～i为根的树
            for (int root=1; root<=i; root++) {
                vector<TreeNode*> left_children = states[root-1];
                vector<TreeNode*> right_children = states[i-root];
                for (auto &left_child: left_children) {
                    for (auto &right_child: right_children) {
                        TreeNode* node = new TreeNode(root);
                        node->left = left_child;
                        node->right = clone(right_child, root);
                        cur.push_back(node);
                    }
                }
            }
            states[i] = cur;
        }
        return states.back();

    }
        
    
};
// @lc code=end

