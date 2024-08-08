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

    ListNode* swapPairs(ListNode* head) {
        ListNode *s, *r, *q;
        q = head;
        r = NULL;
        int c = 0, k = 2;
        while(q && c < k) {
            s = r;
            r = q;
            q = q->next;
            r->next = s;
            c++;
        }
        if(head)
            head->next = swapPairs(q);
        return r;    
    }
};