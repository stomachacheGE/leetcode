/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        // get length
        int m=0, n=0;
        ListNode *nodeA = headA, *nodeB = headB;
        while (nodeA) {
            nodeA = nodeA->next;
            m++;
        }
        while (nodeB) {
            nodeB = nodeB->next;
            n++;
        }
        // cout << "m: " << m << ", n: " << n << endl;
        int counter = 1;
        if (m > n) {
            while (counter++ <= m-n) {
                headA = headA->next;
            } 
        } else {
            while (counter++ <= n-m) {
                headB = headB->next;
            }
        }
        
        while (headA) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // solution one 
        // 先统计各自长度，快指针先走长度差，然后一起走直到重合
        // int len1 = 0, len2 = 0;
        // ListNode *node1 = headA, *node2 = headB;
        // while (node1) {
        //     len1++;
        //     node1 = node1->next;
        // }
        
        // while (node2) {
        //     len2++;
        //     node2 = node2->next;
        // }

        // int diff = abs(len1 - len2);
        // if (len1 > len2) {
        //     node1 = headA;
        //     node2 = headB;
        // } else {
        //     node1 = headB;
        //     node2 = headA;
        // }

        // while (diff-- > 0) {
        //     node1 = node1->next;
        // }
        // while (node1 != node2) {
        //     node1 = node1->next;
        //     node2 = node2->next;
        // }
        // return node1;

        // solution two
        // ref.:https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode/
        // 分别遍历，一旦遍历到NULL则连接到另外一个头部，直到相遇
        ListNode* node1 = headA, *node2 = headB;
        while (node1 != node2) {
            // 注意，这会在不想交的情况下产生死循环
            // node1 = node1->next;
            // node2 = node2->next;
            // if (!node1) node1 = headB;
            // if (!node2) node2 = headA;
            // 此种写法保证在不想交的情况下一起到达null
            node1 = node1 ? node1->next : headB;
            node2 = node2 ? node2->next : headA;
        }
        return node1;
    }
};
// @lc code=end

