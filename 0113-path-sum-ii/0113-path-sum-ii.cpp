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

    void compute(int a[], int n, vector<vector<int>> &res, int s) {
        vector<int> ans;
        int sum = 0;
        for(int i=0; i<n ; i++) {
            sum += a[i];
            ans.push_back(a[i]);
        }
        if(sum == s)
            res.push_back(ans);
    }

    void pathSumUtil(TreeNode* root, int path[], int pathlen, vector<vector<int>> &res, int s) {
        if(root == NULL)
            return;
        path[pathlen++] = root->val;
        if(root->left == NULL && root->right == NULL)
            compute(path, pathlen, res, s);
        pathSumUtil(root->left, path, pathlen, res, s);
        pathSumUtil(root->right, path, pathlen, res, s);        
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        int path[5001];
        pathSumUtil(root, path, 0, res, targetSum);
        return res;        
    }
};