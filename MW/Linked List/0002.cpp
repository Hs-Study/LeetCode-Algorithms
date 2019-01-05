/*
 * Name:    Add Two Numbers
 * Tag:     Linked List
 * Level:   Medium


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* p1;
    ListNode* p2;
    ListNode* ans = NULL;
    ListNode* p3 = NULL;
    int cascade = 0;

    int cascadeNum(int sum) {
        cascade = sum / 10;
        return sum % 10;
    }
    
    void appendNum(int sum) {
        ListNode* current = new ListNode(sum);
        if (ans == NULL) {
            ans = current;
            p3 = ans;
        } else {
            p3->next = current;
            p3 = current;
        }
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        p1 = l1, p2 = l2, p3 = NULL, ans = NULL;

        for (; p1 != NULL && p2 != NULL; p1=p1->next, p2=p2->next) {
            int a = p1->val + p2->val + cascade;
            a = cascadeNum(a);
            appendNum(a);
        }
        for (; p1 != NULL; p1=p1->next) {
            int a = p1->val + cascade;
            a = cascadeNum(a);
            appendNum(a);
        }
        for (; p2 != NULL; p2=p2->next) {
            int a = p2->val + cascade;
            a = cascadeNum(a);
            appendNum(a);
        }
        while (cascade > 0) {
            int a = cascade;
            a = cascadeNum(a);
            appendNum(a);
        }
        
        return ans;
    }
};