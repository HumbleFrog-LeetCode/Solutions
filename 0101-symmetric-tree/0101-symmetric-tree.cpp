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

    bool symmetric(TreeNode* a, TreeNode* b) {
        if(a == NULL && b == NULL)
            return true;
        if(a == NULL || b == NULL)
            return false;
        return (a->val == b->val && symmetric(a->left, b->right) && symmetric(a->right, b->left));
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return  true;
        return symmetric(root->left, root->right);
    }
};