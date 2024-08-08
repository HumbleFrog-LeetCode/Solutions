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

    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = NULL, *prev = NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto x: lists) {
            if(x)
                pq.push(x);
        }
        if(pq.empty())
            return res;
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            if(temp->next)
                pq.push(temp->next);
            if(res == NULL)
                res = temp;
            else
                prev->next = temp;
            prev = temp;            
        }   
        return res; 
    }
};