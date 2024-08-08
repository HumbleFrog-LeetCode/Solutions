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
    int diameter(TreeNode* root, int &height) {
        int lh = 0, rh = 0, ld = 0, rd = 0;
        if(root == NULL) {
            height = 0;
            return 0;
        }

        ld = diameter(root->left, lh);
        rd = diameter(root->right, rh);

        height = 1 + max(lh, rh);
        return max({ld, rd, lh + rh});
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;
        return diameter(root, height);
    }
};