/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        // solution one
        vector<vector<int>> res;
        if (!root) return res;
        deque<Node*> q;
        q.push_back(root);
        while (!q.empty()) {
            int num = q.size();
            vector<int> level;
            while (num-- > 0) {
                Node* node = q.front();
                q.pop_front();
                level.push_back(node->val);
                for (auto &child: node->children) {
                    q.push_back(child);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};
// @lc code=end

