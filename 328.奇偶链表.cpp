/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        // 实际上此题不用dummy node也可以
        if (!head || !head->next || !head->next->next) return head;
        ListNode *odd_dummy = new ListNode(-1), *even_dummy = new ListNode(-1), *cur = head, *temp;
        ListNode *odd = odd_dummy, *even = even_dummy;
        bool oddth = true;
        while (cur) {
            temp = cur->next;
            cur->next = NULL;
            if (oddth) {
                odd->next = cur;
                odd = odd->next;
                oddth = false;
            } else {
                even->next = cur;
                even = even->next;
                oddth = true;
            }
            cur = temp;
        }
        odd->next = even_dummy->next;
        return odd_dummy->next;
    }
};
// @lc code=end

