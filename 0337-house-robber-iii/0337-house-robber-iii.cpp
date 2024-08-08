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
     
    vector<int> robUtil(TreeNode* root) {
        if(root == NULL)
            return {0, 0};
        vector<int> left = robUtil(root->left);
        vector<int> right = robUtil(root->right);

        vector<int> res(2, 0); // {include, exclude}
        res[0] = root->val + left[1] + right[1];
        res[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return res;
    }

    int rob(TreeNode* root) {
        vector<int> res = robUtil(root);
        return max(res[0], res[1]);
    }
};