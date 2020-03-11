/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* findMiddle(ListNode* node) {
        if (node == NULL || node->next == NULL) return node;
        ListNode *slow = node, *fast = node->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* node) {
        if (node == NULL || node->next == NULL) return node;
        
        ListNode* prev = NULL;
        ListNode* curt = node;
        
        while (curt) {
            ListNode* temp = curt->next;
            curt->next = prev;
            prev = curt;
            curt = temp;
        }
        return prev;
    }
    
    ListNode* merge(ListNode* node_1, ListNode* node_2) {
        ListNode *dummy = new ListNode(-1);
        int counter = 1;
        while (node_1 || node_2) {
            if (counter % 2 == 1) {
                dummy->next = node_1;
                node_1 = node_1->next;
                dummy = dummy->next;
                dummy->next = NULL;
            } else {
                dummy->next = node_2;
                node_2 = node_2->next;
                dummy = dummy->next;
                dummy->next = NULL;
            }
            counter++;
        }
        
        return dummy->next;
    }

    // ref.:https://leetcode-cn.com/problems/reorder-list/solution/3ge-bu-zou-jian-dan-yi-dong-by-wang_dong/
    ListNode* merge1(ListNode* left, ListNode* right){
        ListNode* leftTemp;
        ListNode* rightTemp;
        while (left && right) {
            //1. 保存next节点
            leftTemp = left->next;
            rightTemp = right->next;

            //2. 将右链表的第一个节点插入到左链表中
            left->next = right;
            right->next = leftTemp;

            //3. 移动left和right指针
            left = leftTemp;
            right = rightTemp;
        }
        return left;
    }

public:
    void reorderList1(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        
        // find left-middle
        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = NULL;
        ListNode* left = head;
        
        // reverse right part
        ListNode* right_reversed = reverse(right);
        
        // merge
        head = merge1(left, right_reversed);
        return;
    }

    void reorderList(ListNode* head) {
        // recursion
        // ref.:https://leetcode-cn.com/problems/reorder-list/solution/di-gui-cong-shou-wei-liang-duan-jiao-huan-jie-dian/
        if (!head || !head->next) return;
        reorderListRecursive(head);
        
    }

    ListNode* reorderListRecursive(ListNode* node) {
        // 注意只有两个结点的时候也应该直接返回，
        // 否则会出现无限循环
        if (!node || !node->next || !node->next->next) return node;
        ListNode* tail = node, *prev_tail = NULL, *temp = node->next;
        while (tail->next) {
            prev_tail = tail;
            tail = tail->next;
        }
        prev_tail->next = NULL;
        node->next = tail;
        tail->next = reorderListRecursive(temp);
        return node;
    }
};
// @lc code=end

