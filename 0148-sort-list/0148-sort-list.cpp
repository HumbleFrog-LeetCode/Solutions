/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* sortedMerge(ListNode* a, ListNode* b) {
        ListNode *res = NULL;
        if(a == NULL)
            return b;
        if(b == NULL)
            return a;

        if(a->val <= b->val) {
            res = a;
            res->next = sortedMerge(a->next, b);
        }  
        else {
            res = b;
            res->next = sortedMerge(a, b->next);
        } 
        return res; 
    }

    void split(ListNode* head, ListNode *&a, ListNode *&b) {
        ListNode *slow = head, *fast = head, *prev = NULL;
        if(head == NULL || head->next == NULL) {
            a = head;
            b = NULL;
            return;
        }

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        a = head;
        b = slow;
        prev->next = NULL;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *a = NULL, *b = NULL;    
        split(head, a, b);    
        a = sortList(a);
        b = sortList(b);
        return sortedMerge(a, b);
    }
};