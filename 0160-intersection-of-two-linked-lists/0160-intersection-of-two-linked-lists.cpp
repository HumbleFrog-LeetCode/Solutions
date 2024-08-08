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

    int count(ListNode *head) {
        ListNode *temp = head;
        int c = 0;
        while(temp) {
            temp = temp->next;
            c++;
        }
        return c;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = count(headA);
        int n = count(headB);
        ListNode *smaller = headA, *larger = headB;
        if(n < m) {
            smaller = headB;
            larger = headA;
        }
        
        for(int i = 0; i < abs(m-n); i++) {
            larger = larger->next;
        }

        while(smaller && larger) {
            if(smaller == larger)
                return smaller;
            smaller = smaller->next;
            larger = larger->next;    
        }
        return NULL;
    }
};