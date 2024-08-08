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

    TreeNode* buildTree(vector<int> &preorder, int &index, int low, int high, int size) {
        if(index >= size || low > high)
            return NULL;
        TreeNode* root = new TreeNode(preorder[index++]);

        if(low == high)
            return root;
        
        int i;
        for(i = low ; i <= high; i++) {
            if(root->val < preorder[i])
                break;
        }        

        root->left = buildTree(preorder, index, index, i-1, size);
        root->right = buildTree(preorder, index, i, high, size);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        int size = preorder.size();
        return buildTree(preorder, index, 0, size-1, size);
    }
};