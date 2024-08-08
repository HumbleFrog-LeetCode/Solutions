/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        Node *current = head;

        // Create copy of nodes and link them in-between the nodes of the original Linked List
        while(current) {
            Node* temp = new Node(current->val);
            temp->next = current->next;
            current->next = temp;
            current = temp->next;
        }  

        // Set the random pointers of the copied list
        current = head;
        while(current) {
            if(current->next)
                current->next->random = current->random ? current->random->next : current->random;
            current = current->next ? current->next->next : current->next;
        }

        // Dissociating the original list from the copied list
        Node *original = head;
        Node *copy = head->next;
        Node *start = copy;
        while(original && copy) {
            original->next = original->next ? original->next->next : original->next;
            copy->next = copy->next ? copy->next->next : copy->next;
            original = original->next;
            copy = copy->next;
        }
        return start;
    }
};