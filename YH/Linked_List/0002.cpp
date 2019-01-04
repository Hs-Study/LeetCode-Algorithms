/* 
 * Name:    Add Two Numbers
 * Tag:     Linked List, Math 
 * Level:   Medium
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1, l2, 0);
    }
    
    ListNode* solve(ListNode *l1, ListNode *l2, int add) {
        int a=0, b=0;
        ListNode *newNode;
        if(l1 || l2) {
            if(l1) {
                a = l1->val;
                l1 = l1->next;
            }    
            if(l2) {
                b = l2->val;
                l2 = l2->next;
            }
        }
        else {
            if(add) return new ListNode(add);
            else return 0;
        }
        int val = add+a+b;
        newNode = new ListNode(val%10);
        newNode->next = solve(l1, l2, val/10);
        return newNode;
    }
};
