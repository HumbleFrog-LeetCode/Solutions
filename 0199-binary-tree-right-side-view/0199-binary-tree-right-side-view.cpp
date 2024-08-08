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
    void rightView(TreeNode* root, int level, int &maxLevel, vector<int> &res) {
        if(root == NULL)
            return;

        if(level > maxLevel) {
            maxLevel = level;
            res.push_back(root->val);
        }    
        rightView(root->right, level+1, maxLevel, res);
        rightView(root->left, level+1, maxLevel, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        int maxLevel = 0;
        vector<int> res;
        rightView(root, 1, maxLevel, res);
        return res;
    }
};