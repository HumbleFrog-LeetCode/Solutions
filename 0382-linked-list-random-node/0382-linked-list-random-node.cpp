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
    ListNode* head;

public:
    Solution(ListNode* head) : head(head){
    }
    
    int getRandom() {
        int i = 0;
        ListNode* temp = head, *randomNode = NULL;
        while(temp) {
            i++;
            int random = rand() % i;
            if(random == i-1)
                randomNode = temp;
            temp = temp->next;    
        }
        return randomNode->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */