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

    ListNode* reverse(ListNode* head, int k) {
        ListNode *s, *r, *q;
        q = head;
        r = NULL;
        int c = 0;
        while(q && c < k) {
            s = r;
            r = q;
            q = q->next;
            r->next = s;
            c++;
        }
        if(head)
            head->next = reverse(q, k);
        return r;    
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head, *start, *end;
        int c = 1, total = 0;
        while(temp) {
            if(c == k) {
                start = temp;
                c = 0;
            }
            temp = temp->next;
            c++;
        }

        end = start->next;
        start->next = NULL;

        head = reverse(head, k);

        temp = head;
        while(temp->next) 
            temp = temp->next;
        
        temp->next = end;
        return head;
    }
};