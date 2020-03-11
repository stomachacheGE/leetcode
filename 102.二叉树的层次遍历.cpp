/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
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
    void dfs(TreeNode* root, int dep){
            if(!root) return;
            if(dep == result.size()) result.emplace_back();
            result[dep].push_back(root->val);
            dfs(root->left, dep+1);
            dfs(root->right, dep+1);
        }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // solution one (v2)
        // vector<vector<int>> res;
        // if (!root) return res;
        // deque<TreeNode*> q;
        // q.push_back(root);
        // q.push_back(NULL);
        // while (!q.empty() && q.front()) {
        //     vector<int> level;
        //     while (true) {
        //         TreeNode* node = q.front();
        //         q.pop_front();
        //         if (!node) break;
        //         level.push_back(node->val);
        //         if (node->left) q.push_back(node->left);
        //         if (node->right) q.push_back(node->right);
        //     }
        //     res.push_back(level);
        //     q.push_back(NULL);
        // }
        // return res;

        // solution one (v2)
        // use queue size instead of NULL
        // vector<vector<int>> res;
        // if (!root) return res;
        // deque<TreeNode*> q;
        // q.push_back(root);
        // while (!q.empty()) {
        //     vector<int> level;
        //     int num = q.size();
        //     while (num-- > 0) {
        //         TreeNode* node = q.front();
        //         q.pop_front();
        //         level.push_back(node->val);
        //         if (node->left) q.push_back(node->left);
        //         if (node->right) q.push_back(node->right);
        //     }
        //     res.push_back(level);
        // }
        // return res;
        
        // solution two (v2)
        // ref.:https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/ceng-ci-bian-li-bfs-by-user2511z/
        // dfs
        dfs(root, 0);
        return result;
    }
};
// @lc code=end

