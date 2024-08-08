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

    bool isPalindromeUtil(ListNode *&left, ListNode *right) {
        if(right == NULL)
            return true;
        bool isp1 = isPalindromeUtil(left, right->next);
        if(isp1 == false)
            return false;
        bool isp2 = left->val == right->val;
        left = left->next;
        return isp2;       
    }

    bool isPalindrome(ListNode* head) {
        return isPalindromeUtil(head, head);
    }
};