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
    
    void leftView(TreeNode* root, int level, int &max_level, int &res) {
        if(root == NULL)
            return;
        if(max_level < level) {
            res = root->val;
            max_level = level;
        }    
        leftView(root->left, level+1, max_level, res);
        leftView(root->right, level+1, max_level, res);
    }

    int findBottomLeftValue(TreeNode* root) {
        int res = 0, max_level = 0;
        leftView(root, 1, max_level, res);
        return res;
    }
};