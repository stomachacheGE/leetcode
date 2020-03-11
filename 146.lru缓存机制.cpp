/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
class LRUCache {
private:

    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int x, int y): key(x), val(y), next(NULL), prev(NULL) {}
    };

    int _capacity;
    unordered_map<int, Node*> table;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void moveToTail(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }
public:
    LRUCache(int capacity) {

        // solution one
        // hashmap + 双向链表
        // Ref.:https://leetcode-cn.com/problems/lru-cache/solution/shu-ju-jie-gou-fen-xi-python-ha-xi-shuang-xiang-li/
        _capacity = capacity;
        head->next = tail;
        tail->prev = head;

        // solution two
        // 不用双向链表，用stl::list代替 (TODO)
        // Ref.:https://leetcode-cn.com/problems/lru-cache/comments/59412

    }
    
    int get(int key) {
        auto found = table.find(key);
        if (found != table.end()) {
            moveToTail(table[key]);
            return (table[key])->val;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        // check a key is ready there
        auto it = table.find(key);
        if (it != table.end()) {
            table[key]->val = value;
            moveToTail(table[key]);
            return;
        } 

        if (table.size() == _capacity) {
            int candidate = head->next->key;
            auto it = table.find(candidate);
            if (it == table.end()) return;
            table.erase(it);
            head->next = head->next->next;
            head->next->prev = head;
        }

        Node* node = new Node(key, value);
        table[key] = node;
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

