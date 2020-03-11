/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        // solution one (v2)
        // two pointers
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *ahead = head, *behind = dummy;
        while (n-- > 0) {
            ahead = ahead->next;
        }
        while (ahead != NULL) {
            ahead = ahead->next;
            behind = behind->next;
        }
        behind->next = behind->next->next;
        return dummy->next;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // solution one (v2)
        ListNode *dummy, *ahead=head, *behind=head;
        dummy = new ListNode(-1);
        dummy->next = head;
        behind = dummy;
        int count = 0;
        while (count++ < n) {
            ahead = ahead->next;
        }
        while (ahead) {
            ahead = ahead->next;
            behind = behind->next;
        }
        behind->next = behind->next->next;
        return dummy->next;
    }
};
// @lc code=end

