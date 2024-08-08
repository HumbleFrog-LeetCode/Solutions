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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *a = NULL, *b = NULL, *prev_a = NULL, *prev_b = NULL, *temp = head;
        while(temp) {
            if(temp->val < x) {
                if(prev_a == NULL)
                    a = temp;
                else
                    prev_a->next = temp;
                prev_a = temp;        
            }
            else {
                if(prev_b == NULL)
                    b = temp;
                else
                    prev_b->next = temp;
                prev_b = temp;
            }
            temp = temp->next;
        }
        if(a == NULL) {
            prev_b->next = NULL;
            return b;
        }
            
        if(b == NULL) {
            prev_a->next = NULL;
            return a;
        }
               
        prev_a->next = b;
        prev_b->next = NULL;
        return a;
    }
};