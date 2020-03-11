/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // solution one (v2)
        // int len1 = 0, len2 = 0;
        // ListNode *node1 = l1, *node2 = l2, *res;
        // while (node1) {
        //     len1++;
        //     node1 = node1->next;
        // }
        
        // while (node2) {
        //     len2++;
        //     node2 = node2->next;
        // }

        // if (len1 > len2) {
        //     node1 = l1;
        //     node2 = l2;
        //     res = l1;
        // } else {
        //     node1 = l2;
        //     node2 = l1;
        //     res = l2;
        // }
        // // int count = abs(len1 - len2);
        // // while (count-- > 0) {
        // //     node1 = node1->next;
        // // }
        // int carry = 0;
        // ListNode* prev = NULL;
        // while (node1) {
        //     int temp = node1->val;
        //     temp += node2 ? node2->val + carry : carry;
        //     carry = temp / 10;
        //     node1->val = temp % 10;
        //     prev = node1;
        //     node1 = node1->next;
        //     if (node2) node2 = node2->next;
        // }
        // if (carry) {
        //     ListNode* node = new ListNode(1);
        //     prev->next = node;
        // }

        // return res;   

        // solution two (v2)
        // ref.:https://leetcode-cn.com/problems/add-two-numbers/solution/liang-shu-xiang-jia-by-leetcode/
        ListNode* dummyHead = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = dummyHead;
        int carry = 0;
        while (p || q) {
            int x = p ? p->val : 0;
            int y = q ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p) p = p->next;
            if (q) q = q->next;
        }
        if (carry) {
            curr->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
};
// @lc code=end

