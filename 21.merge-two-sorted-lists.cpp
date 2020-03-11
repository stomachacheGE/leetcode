/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (47.09%)
 * Total Accepted:    586K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ////////// Solution One //////////
        // ListNode head = ListNode(INT_MIN);
        // head.next = l1;
        // l1 = &head;
        // while (l2) {
        //     // find the localtion to insert in l1
        //     while (l1) {
        //         if (!l1->next) break;
        //         if (l1->next->val > l2->val) {
        //             break;
        //         }
        //         l1 = l1->next;
        //     } 

        //     // if the last node in l1 is reached,
        //     // simply attach l2 to the tail of l1 
        //     if (!l1->next) {
        //         l1->next = l2;
        //         break;
        //     }

        //     // insert the node to l1
        //     ListNode *temp = l2->next;
        //     l2->next = l1->next;
        //     l1->next = l2;
        //     l1 = l1->next;
        //     l2 = temp;
        // }
        // return head.next;

        ////////// Solution Two //////////
        // Ref. https://leetcode.com/problems/merge-two-sorted-lists/discuss/9714/14-line-clean-C%2B%2B-Solution
        ListNode dummy = ListNode(INT_MIN);
        ListNode* tail = &dummy;

        while(l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ?  l1 : l2;
        return dummy.next;
    }
};
