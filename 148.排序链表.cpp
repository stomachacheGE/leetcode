/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* findMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        // the result has to be left-middle 
        ListNode *fast = head->next, *slow = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* node = dummy;
        
        while (left && right) {
            if (left->val <= right->val) {
                node->next = left;
                left = left->next;
                node = node->next;
                node->next = NULL;
            } else {
                node->next = right;
                right = right->next;
                node = node->next;
                node->next = NULL;
            }
        }
        
        if (left)  node->next = left;
        if (right) node->next = right;
        
        return dummy->next;   
    }

    ListNode* cut(ListNode* start, int num) {

        ListNode* node = start, *res;
        int count = 1;
        while (node && count++ < num) {
            node = node->next;
        }
        if (!node) return node;
        res = node->next;
        node->next = NULL;
        return res;
    }

public:
    ListNode* sortList1(ListNode* head) {

        // 递归，时间复杂度O(nlogn)
        // 因为递归栈的原因，空间复杂度应该是O(n)
        if (!head || !head->next) return head;

        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = NULL;

        head = sortList(head);
        right = sortList(right);

        return merge(head, right);
    }

    ListNode* sortList(ListNode* head) {

        // bottom-up 归并排序迭代版，不用递归
        // cut函数将链表切分小段并返回链表剩余部分的头一个结点
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1), *node = head, *cur, *left, *right, *tail;
        dummy->next = head;
        int len = 0;
        while (node) {
            len++;
            node = node->next;
        }
        for (int i = 1; i < len; i *= 2) { // i must start with 1
            cur = dummy->next;
            tail = dummy;
            while (cur) {
                left = cur;
                right = cut(left, i);
                cur = cut(right, i);
                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummy->next;
    }


};
// @lc code=end

