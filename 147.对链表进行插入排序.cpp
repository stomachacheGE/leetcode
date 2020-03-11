/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList1(ListNode* head) {

        // solution one
        // naive implementation
        
        if (head == NULL) return NULL;
        int nums = 0;
        ListNode*prev = head, *cur = head->next, *dummy = new ListNode(-1), *node;
        dummy->next = head;
        while (cur) {

            node = dummy;
            // find where to insert
            while (node->next->val < cur->val) {
                node = node->next;
            }
            // if the element is alreay in order
            if (node ==  prev) {
                prev = cur;
                cur = cur->next;
                continue;
            }
            prev->next = cur->next;
            cur->next = node->next;
            node->next = cur;
            cur = prev->next;
        }
        return dummy->next;
    }

    ListNode* insertionSortList(ListNode* head) {

        // 能通过但是不如v1解法好写
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = head->next, *node = dummy, *temp1;
        head->next = NULL;
        while (cur) {
            // cout << "cur=" << cur->val << endl;
            node = dummy;
            while (node->next && node->next->val < cur->val) {
                node = node->next;
            }
            if (node->next == NULL) {
                temp1 = cur->next;
                cur->next = NULL;
                node->next = cur;
                cur = temp1;
                continue;
            }

            temp1 = cur->next;
            cur->next = node->next;
            node->next = cur;
            cur = temp1;
        }
        return dummy->next;
    }

};
// @lc code=end

