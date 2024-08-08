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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* temp = head, *curr;
        while(temp->next) {
            if(temp->next->val != temp->val)
                temp = temp->next;
            else {
                curr = temp->next;
                temp->next = curr->next;
                delete curr;
            }    
        }
        return head;
    }
};