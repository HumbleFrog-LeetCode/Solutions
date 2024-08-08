/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void flat(TreeNode* root, TreeNode* &head) {
        if(root == NULL)
            return;
        flat(root->right, head); 
        flat(root->left, head);  
        root->left = NULL;
        root->right = head;
        head = root; 
    }

    void flatten(TreeNode* root) {
        TreeNode *head = NULL;
        flat(root, head);
        root = head;
    }
};