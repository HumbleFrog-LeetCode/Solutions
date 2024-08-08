/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    Node* getNext(Node* p) {
        Node* temp = p->next;
        while(temp) {
            if(temp->left)
                return temp->left;
            if(temp->right)
                return temp->right;
            temp = temp->next;
        }
        return NULL;
    }

    Node* connect(Node* root) {
        Node* p = root;
        if(!p)
            return NULL;
        p->next == NULL;    
        while(p) {
            Node* q = p;
            while(q) {
                if(q->left) {
                    if(q->right)
                        q->left->next = q->right;
                    else
                        q->left->next = getNext(q);    
                }
                if(q->right)
                    q->right->next = getNext(q);
                q = q->next;    
            }
            if(p->left)
                p = p->left;
            else if(p->right)
                p = p->right;
            else
                p = getNext(p);        
        }
        return root;  
    }
};