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

    int count(ListNode* head) {
        int c = 0;
        ListNode *temp = head;
        while(temp) {
            temp = temp->next;
            c++;
        }
        return c;
    }

    ListNode* rotate(ListNode* head, int k, int n) {
        ListNode *temp = head, *tmp, *tmp2;
        for(int i=1; i<n-k; i++)
            temp = temp->next;    
        tmp = temp->next;
        temp->next = NULL; 
        tmp2 = tmp;  
        while(tmp2->next)
            tmp2 = tmp2->next;   
        tmp2->next = head;
        return tmp;     
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0)
            return head;

        int n = count(head);
        k = k % n;
        if(k == 0)
            return head;
        return rotate(head, k, n);
    }
};