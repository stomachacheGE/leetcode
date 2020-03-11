/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
     Node* cloneGraph1(Node* node) {
        ///////////// Solution One //////////////
        // Nine Chapters. 88.21%, 49.10%
        // step 1: use bfs to get all nodes
        unordered_set<Node*> nodes = getAllNodes(node);
        
        // step 2: copy nodes
        unordered_map<Node*, Node*> old2new;
        for (auto &old_node: nodes) {
            Node* new_node = new Node();
            new_node->val = old_node->val;
            old2new.insert(make_pair(old_node, new_node));
        }
        
        // step 3: copy edges
        for (auto &old_node: nodes) {
            Node* new_node = (old2new.find(old_node))->second;
            for (auto &neighbor: old_node->neighbors) {
                Node* new_neighbor = (old2new.find(neighbor))->second;
                (new_node->neighbors).push_back(new_neighbor);
            }
        }
        return (old2new.find(node))->second;
    }

    Node* cloneGraph(Node* node) {

        // solution one
        // bfs遍历，同时生成新结点和连接边
        if (!node) return node;
        unordered_map<Node*, Node*> old2new;
        deque<Node*> q;
        q.push_back(node);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop_front();
            if (old2new.count(cur) == 0) {
                Node* new_node = new Node(cur->val);
                old2new.insert(make_pair(cur, new_node));
            }
            for (auto &neighbor: cur->neighbors) {
                if (old2new.count(neighbor) == 0) {
                    q.push_back(neighbor); // only push when it has not been seen
                    Node* new_neighbor = new Node(neighbor->val);
                    old2new.insert(make_pair(neighbor, new_neighbor));
                } 
                old2new[cur]->neighbors.push_back(old2new[neighbor]);

            }
        }
        return old2new[node];
    }
private:
    unordered_set<Node*> getAllNodes(Node* node) {
        
        queue<Node*> queue;
        queue.push(node);
        unordered_set<Node*> nodes;
        nodes.insert(node);
        
        while (!queue.empty()) {
            Node* cur = queue.front();
            queue.pop();
            for (int i=0; i<(cur->neighbors).size(); i++) {
                // add a node to set
                Node* neighbor = (cur->neighbors)[i];
                if (nodes.count(neighbor) == 0) {
                    nodes.insert(neighbor);
                    queue.push(neighbor);
                }
            }
        }
        return nodes;
    }
};
// @lc code=end

