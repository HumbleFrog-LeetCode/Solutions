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

    bool isBalancedUtil(TreeNode* root, int &height) {
        int lh = 0, rh = 0; 
        if(root == NULL) {
            height = 0;
            return true;
        } 

        int l = isBalancedUtil(root->left, lh);
        int h = isBalancedUtil(root->right, rh);

        height = 1 + max(lh, rh);

        if(abs(lh-rh) >=2)
            return false;
        return l && h;
    }

    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalancedUtil(root, height);
    }
};