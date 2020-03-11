/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
public:
    ListNode* partition1(ListNode* head, int x) {
        
        // solution one
        // 两个链表分别保存小于或者等于x的结点
        if (head == NULL) return NULL;
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode *node1 = dummy1, *node2 = dummy2;
        while (head != NULL) {
            if (head->val < x) {
                node1->next = head;
                node1 = node1->next;
                head = head->next;
                // to break original connections, 
                // otherwise circle in the result list
                node1->next = NULL;
            } else {
                node2->next = head;    
                node2 = node2->next; 
                head = head->next;
                // to break original connections, 
                // otherwise circle in the result list
                node2->next = NULL;
            }
        }
        // cout << "exit" << endl;
        node1->next = dummy2->next;
        return dummy1->next;
    }

    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode *dummy1 = new ListNode(-1), *dummy2 = new ListNode(-1);
        ListNode *part1 = dummy1, *part2 = dummy2;
        while (head) {
            if (head->val < x) {
                part1->next = head;
                head = head->next;
                part1 = part1->next;
                part1->next = NULL;
            } else {
                part2->next = head;
                head = head->next;
                part2 = part2->next;
                part2->next = NULL;
            }
        }
        part1->next = dummy2->next;
        return dummy1->next;
    }
};
// @lc code=end

