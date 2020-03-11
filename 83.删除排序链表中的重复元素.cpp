/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates1(ListNode* head) {
        // V1. Recursive
        // if (head == NULL || head->next == NULL) return head;
        // if (head->val == head->next->val) {
        //     head->next = head->next->next;
        //     return deleteDuplicates(head);
        // } else {
        //     // 如果不等，head的next应该指向next去重后的结果
        //     head->next = deleteDuplicates(head->next);
        //     return head;
        // }
        
        // V1.1 Better recursive
//         if (head == NULL || head->next == NULL) return head;
//         head->next = deleteDuplicates(head->next)
//         if (head->val == head->next->val) head = head->next;
//         return head;
        
        // V2. Loop
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* prev = head;
        ListNode* cur  = head;
        
        while (cur) {
            while (cur && prev->val == cur->val) cur = cur->next;
            prev->next = cur;
            prev = prev->next;
        }
        return head;
        
    }

    ListNode* deleteDuplicates(ListNode* head) {

        // solution one 
        // if (!head) return head;
        // ListNode* dummy = new ListNode(-1);
        // dummy->next = head;
        // ListNode *behind = dummy, *ahead = head;
        // while (ahead) {
        //     while (ahead && ahead->next && ahead->val == ahead->next->val) {
        //         ahead = ahead->next;
        //     }
        //     behind->next = ahead;
        //     ahead = ahead->next;
        //     behind = behind->next;
        // }
        // return dummy->next;

        // solution two
        // recursion
        if (!head) return head;
        while (head->next && head->val == head->next->val) {
            head = head->next;
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};
// @lc code=end

