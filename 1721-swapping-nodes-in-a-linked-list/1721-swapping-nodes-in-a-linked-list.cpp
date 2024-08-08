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

    int count(ListNode *head) {
        ListNode *temp = head;
        int c = 0;
        while(temp) {
            temp = temp->next;
            c++;
        }
        return c;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        int n = count(head);
        if(2 * k - 1 == n)
            return head;

        ListNode *x = head, *x_prev = NULL;    
        for(int i=1; i<k; i++) {
            x_prev = x;
            x = x->next;
        }  

        ListNode *y = head, *y_prev = NULL;    
        for(int i=1; i<n-k+1; i++) {
            y_prev = y;
            y = y->next;
        }

        if(x_prev)
            x_prev->next = y;
        if(y_prev)
            y_prev->next = x;

        ListNode *temp = x->next;
        x->next = y->next;
        y->next = temp;

        if(k == 1)
            return y;
        if(k == n)
            return x;   

        return head;                      
    }
};