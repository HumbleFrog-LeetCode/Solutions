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

   ListNode* reverse(ListNode* head) {
        ListNode *s, *r, *q;
        q = head;
        r = NULL;
        while(q) {
            s = r;
            r = q;
            q = q->next;
            r->next = s;
        }
        return r;
   }

    ListNode* removeNodes(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        head = reverse(head);
        ListNode *temp = head->next;
        int maxi = head->val;
        ListNode *prev = head;
        while(temp) {
            if(temp->val >= maxi) {
                maxi = temp->val;
                prev = temp;
                temp = temp->next;
            }
            else {
                prev->next = temp->next;
                ListNode *curr = temp;
                temp = temp->next;
                delete curr; 
            }
        }
        return reverse(head);
    }
};