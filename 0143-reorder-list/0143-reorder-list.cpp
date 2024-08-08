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

    ListNode *reverse(ListNode *head) {
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

    void merge(ListNode *a, ListNode *b) {
        ListNode *a_curr = a, *b_curr = b, *a_next, *b_next, *prev;
        while(a_curr && b_curr) {
            a_next = a_curr->next;
            b_next = b_curr->next;

            a_curr->next = b_curr;
            b_curr->next = a_next;

            a_curr = a_next;
            prev = b_curr;
            b_curr = b_next;
        }
        prev->next = b_curr;
    }


    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        ListNode *slow = head, *fast = head, *prev, *a, *b, *res = NULL;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        a = head;
        b = reverse(slow);
        
        merge(a, b);
    }
};