/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // if (root == NULL) return "[]";
        string res = "[";
        // bfs
        deque<TreeNode*> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            // check terminating condition
            // If only NULL exists in queue, break
            bool flag = false;
            for (int i=0; i<queue.size(); i++) {
                if (queue[i]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) break;
            
            TreeNode* node = queue.front();
            queue.pop_front();
            if (node) {
                res += to_string(node->val);
            } else {
                res += "null";
            }
            res += ",";
            // cout << "current res: " << res << endl;
            if (node && node->left) {
                queue.push_back(node->left);
            } else {
                queue.push_back(NULL);
            }
            if (node && node->right) {
                queue.push_back(node->right);
            } else {
                queue.push_back(NULL);
            }
        }
        // remove last ','
        res.pop_back();
        res += "]";
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << "deserialize " << data << endl;
        if (data == "[]") return NULL;
        vector<TreeNode*> nodes;
        for (int i=1; i<data.size()-1;) {
            // cout << "i: " << i << endl;
            int len = 0;
            int temp = i;
            // get next val
            while (data[i++] != ',' && i <= data.size()-1) len++;
            // if (i == data.size() - 1) break;
            string cur = data.substr(temp, len);
            // cout << "cur: " << cur << endl;
            if (cur == "null") {
                nodes.push_back(NULL);
                continue;
            }
            TreeNode node = TreeNode(stoi(cur));
            nodes.push_back(&node);
            // cout << "add node" << endl;
            if (nodes.size() == 1) continue;
            int node_idx = nodes.size() - 1;
            int parent_idx = (node_idx - 1) / 2;
            // cout << "parent: " << parent_idx << endl;
            if (2 * parent_idx + 1 == node_idx) {
                nodes[parent_idx]->left = &node;
            } else {
                nodes[parent_idx]->right = &node;
            }
        }
        // cout << "ready to return" << endl;
        Codec codec;
        // cout << codec.serialize(nodes[0]) << endl;
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));