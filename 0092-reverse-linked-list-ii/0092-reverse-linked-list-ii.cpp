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

    ListNode *reverse(ListNode *x) {
        ListNode *s, *r, *q;
        q = x;
        r = NULL;
        while(q) {
            s = r;
            r = q;
            q = q->next;
            r->next = s;
        }
        return r;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        int c = 1;
        ListNode *temp = head, *prev = NULL, *first = NULL, *second = NULL;
        while(temp) {
            if(c == left)
                first = prev;    
            prev = temp; 
            if(c == right)
                second = prev;       
            temp = temp->next;
            c++;
        } 
        
        
        ListNode *start = NULL;
        start = left == 1 ? head : first->next;
        ListNode *end = second->next;
        second->next = NULL;

        ListNode *tmp = reverse(start);
        start->next = end;
        if(first == NULL)
            return tmp;
        first->next = tmp;  
        return head;  
    }
};
