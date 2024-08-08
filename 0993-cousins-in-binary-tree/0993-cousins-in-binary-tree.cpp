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

    int getLevel(TreeNode* root, int x, int level) {
        if(root == NULL)
            return -1;
        if(root->val == x)
            return level;    
        int l = getLevel(root->left, x, level+1);
        return l != -1 ? l : getLevel(root->right, x, level+1);  
    }

    bool isSibling(TreeNode* root, int x, int y) {
        if(root == NULL)
            return false;      
        return (root->left && root->left->val == x && root->right && root->right->val == y
             || root->left && root->left->val == y && root->right && root->right->val == x
             || isSibling(root->left, x, y)
             || isSibling(root->right, x, y));    
    }

    bool isCousins(TreeNode* root, int x, int y) {
        return (getLevel(root, x, 0) == getLevel(root, y, 0) && !isSibling(root, x, y));
    }
};