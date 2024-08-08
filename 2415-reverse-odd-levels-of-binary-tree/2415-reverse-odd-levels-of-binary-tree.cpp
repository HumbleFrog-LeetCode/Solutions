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

    void reverse(TreeNode *a, TreeNode *b, int level) {
        if(a == NULL || b == NULL)
            return;
        if(level&1)    
            swap(a->val, b->val);
        reverse(a->left, b->right, level+1);
        reverse(a->right, b->left, level+1);     
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL)
            return NULL;
        reverse(root->left, root->right, 1);
        return root;
    }
};
