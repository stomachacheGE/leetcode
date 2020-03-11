/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // solution one
        // 用left_first来判断先读左子树还是右子树
        // vector<vector<int>> res;
        // stack<TreeNode*> s;
        // if (root == NULL) return res;
        // s.push(root);
        // bool left_first = false;
        // int last_level_counter = 1, cur_level_counter = 0;
        // vector<int> cur_level = {root->val};
        // vector<TreeNode*> cur_level_nodes;
        // res.push_back(cur_level);
        // while (!s.empty()) {
        //     cur_level.clear();
        //     cur_level_nodes.clear();
        //     // cout << "last_level_counter = " << last_level_counter << endl;
        //     while (last_level_counter-- != 0){
        //         TreeNode* node = s.top();
        //         s.pop();
        //         // cout << "node[" << node->val << "], ";
        //         // cout << "left=" << node->left;
        //         // cout << ", right=" << node->right << endl;
        //         if (left_first) {
        //             if (node->left) {
        //                 cur_level_nodes.push_back(node->left);
        //                 cur_level.push_back(node->left->val);
        //                 cur_level_counter++;
        //             }
        //             if (node->right) {
        //                 cur_level_nodes.push_back(node->right);
        //                 cur_level.push_back(node->right->val);
        //                 cur_level_counter++;
        //             }
        //         } else {
        //             if (node->right) {
        //                 cur_level_nodes.push_back(node->right);
        //                 cur_level.push_back(node->right->val);
        //                 cur_level_counter++;
        //             }
        //             if (node->left) {
        //                 cur_level_nodes.push_back(node->left);
        //                 cur_level.push_back(node->left->val);
        //                 cur_level_counter++;
        //             }
        //         }
        //     }
        //     for (auto &node: cur_level_nodes) {
        //         s.push(node);
        //     }
        //     // cout << "cur_level = " << cur_level_counter << endl;
        //     last_level_counter = cur_level_counter;
        //     cur_level_counter = 0;
        //     left_first = !left_first;
        //     if (cur_level.size() != 0) res.push_back(cur_level);

        // }
        // return res;

        // Solution two
        // 使用两个栈分别存储奇数行和偶数行(TODO)

        // solution one (v2)
        // 使用两个栈分别存储奇数行和偶数行
        vector<vector<int>> res;
        if (!root) return res;
        stack<TreeNode*> odd_stack;
        stack<TreeNode*> even_stack;
        odd_stack.push(root);
        while (!odd_stack.empty() || !even_stack.empty()) {
            vector<int> level;
            while (!odd_stack.empty()) {
                TreeNode* node = odd_stack.top();
                odd_stack.pop();
                level.push_back(node->val);
                if (node->left) even_stack.push(node->left);
                if (node->right) even_stack.push(node->right);
            }
            if (!level.empty()) {
                res.push_back(level);
                continue;
            }
            while (!even_stack.empty()) {
                TreeNode* node = even_stack.top();
                even_stack.pop();
                level.push_back(node->val);
                if (node->right) odd_stack.push(node->right);
                if (node->left) odd_stack.push(node->left);
            }
            res.push_back(level);
        }
        return res;

        // solution two (v2)
        // 不用两个栈，而用双端队列deque (TODO)
        
    }
};
// @lc code=end

