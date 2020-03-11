/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList1(Node* head) {

        // 用unordered_map存储到新结点的对应关系
        if (head == NULL) return NULL;
        Node* dummy = new Node(-1);
        unordered_map<Node*, Node*> map;
        Node* curt = head, *prev = dummy;
        while (curt) {
            Node* new_node = new Node(curt->val);
            map.insert(make_pair(curt, new_node));
            
            prev->next = new_node;
            curt = curt->next;
            prev = prev->next;
        }
        // cout << "here" << endl;
        while (head) {
            Node* new_node = map.find(head)->second;
            if (head->random == NULL) {
                new_node->random = NULL;
            } else {
                Node* random_node = map.find(head->random)->second;
                new_node->random = random_node;
            }
            head = head->next;
        }
        
        return dummy->next;     
    }

    Node* copyRandomList(Node* head) {
        // 两次遍历，第一次将新结点加在旧结点后面
        // 第二次修改random指针
        // 第三次修改next指针
        //ref.:https://leetcode-cn.com/problems/copy-list-with-random-pointer/solution/python-zhan-sheng-9883o1kong-jian-fu-za-du-liang-b/
        if (!head) return head;
        Node* node = head;
        while (node) {
            Node* new_node = new Node(node->val);
            new_node->next = node->next;
            node->next = new_node;
            node = new_node->next;
        }
        node = head;
        while (node) {
            node = node->next;
        }
        node = head;
        while (node) {
            if (node->random) node->next->random = node->random->next;
            node = node->next->next;
        }

        node = head;
        Node* res = head->next; // have to save the res here
        while (node) {
            Node* temp = node->next->next;
            if(temp) node->next->next = temp->next;
            node->next = temp; // recover orignal linked list
            node = node->next;
        }
        return res;

    }
};
// @lc code=end

