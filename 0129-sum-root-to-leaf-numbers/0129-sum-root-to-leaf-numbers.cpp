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

    void compute(int a[], int n, int &res) {
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = ans * 10 + a[i];
        res += ans;    
    }

    void sumUtil(TreeNode* root, int path[], int pathlen, int &res) {
        if(root == NULL)
            return;
        path[pathlen++] = root->val;
        if(root->left == NULL && root->right == NULL)
            compute(path, pathlen, res);
        sumUtil(root->left, path, pathlen, res);
        sumUtil(root->right, path, pathlen, res);
    }

    int sumNumbers(TreeNode* root) {
        int res = 0;
        int path[1000];
        sumUtil(root, path, 0, res);
        return res;
    }
};