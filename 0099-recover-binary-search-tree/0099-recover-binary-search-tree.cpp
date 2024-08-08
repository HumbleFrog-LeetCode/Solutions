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

    void recover(TreeNode* root, vector<TreeNode*> &nodes, TreeNode* &prev) {
        if(root == NULL)
            return;

        recover(root->left, nodes, prev);
        if(prev && prev->val > root->val) {
            if(!nodes[0]) {
                nodes[0] = prev;
                nodes[1] = root;
            }
            else if(nodes[0]) {
                nodes[2] = root;
            }
        }
        prev = root;
        recover(root->right, nodes, prev);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        vector<TreeNode*> nodes(3, NULL);
        recover(root, nodes, prev);
        if(!nodes[2])
            swap(nodes[0]->val, nodes[1]->val);
        else
            swap(nodes[0]->val, nodes[2]->val);
    }
};